#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"
#include "../nodes/node.h"
#include "../nodes/text/text.h"

namespace OPTIC {
    Window::Window(std::string identifier) {
        this->identifier = identifier;
        has_text_support = false;
        finished = true;
        scale = 1;

        SDL_CreateWindowAndRenderer(
            this->title.c_str(),
            this->size.width,
            this->size.height,
            SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_BORDERLESS,
            &(this->sdl_window),
            &(this->sdl_renderer)
        );

        pixel_density = SDL_GetWindowPixelDensity(sdl_window);
    }

    Window::~Window() {

    }

    void Window::bring_to_center() {
        SDL_SetWindowPosition(sdl_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }

    // Tick

    void Window::tick() {
        SDL_SetRenderDrawColor(sdl_renderer, background.red, background.green, background.blue, 255);
        SDL_RenderClear(sdl_renderer);

        for (int i = 0; i < children.size(); i++) {
            OPTIC::Node* this_node = children.at(i).second;

            this_node->tick();
        }

        SDL_RenderPresent(sdl_renderer);
    }


    // Window hide and unhide

    OPTIC::Window* Window::hide() {
        SDL_HideWindow(this->sdl_window);

        return this;
    } 

    OPTIC::Window* Window::show() {
        SDL_ShowWindow(this->sdl_window);

        return this;
    } 


    // Window children functions

    OPTIC::Window* Window::add_child(OPTIC::Node* new_node) {
        new_node->set_parent(this);
        children.push_back(std::pair<std::string, OPTIC::Node*>(new_node->identifier, new_node));

        if (auto* node_cast = dynamic_cast<OPTIC::Text*>(new_node)) {
            try_text_support();
            node_cast->cache();
        } 

        return this;
    }

    OPTIC::Node* Window::get_child(std::string identifier) {
        for (int i = 0; i < children.size(); i++) {
            if (children.at(i).first == identifier) {
                return children.at(i).second;
            }
        }

        return NULL;
    }


    // Window title functions

    OPTIC::Window* Window::set_title(std::string new_title) {
        title = new_title;

        SDL_SetWindowTitle(this->sdl_window, new_title.c_str());

        return this;
    }

    std::string Window::get_title() {
        return this->title;
    }


    // Window size functions

    OPTIC::Window* Window::set_size(Window::Size new_size) {
        size = new_size;

        SDL_SetWindowSize(this->sdl_window, size.width * scale, size.height * scale);

        center.x = size.width / 2;
        center.y = size.height / 2;

        return this;
    }

    Window::Size Window::get_size() {
        return this->size;
    }

    OPTIC::Coord Window::get_center() {
        return this->center;
    }


    // Window scale functions

    OPTIC::Window* Window::set_scale(float new_scale) {
        scale = new_scale;

        set_size(size);

        return this;
    }

    float Window::get_scale() {
        return this->scale;
    }

    float Window::get_pixel_density() {
        return this->pixel_density;
    }

    
    // Window internal pointer functions

    SDL_Window* Window::get_internal_window() { 
        return this->sdl_window;
    }

    SDL_Renderer* Window::get_internal_renderer() {
        return this->sdl_renderer;
    }

    TTF_TextEngine* Window::get_internal_text_engine() {
        if (has_text_support) {
            return this->ttf_engine;
        } else {
            return NULL;
        }
    }


    // Window background color functions

    OPTIC::Window* Window::set_background(OPTIC::Color new_background) {
        this->background = new_background;

        return this;
    }

    OPTIC::Color Window::get_background() {
        return this->background;
    }


    // Window text functions

    void Window::try_text_support() {
        if (!has_text_support) {
            ttf_engine = TTF_CreateRendererTextEngine(sdl_renderer);

            has_text_support = true;
        }
    }
}
