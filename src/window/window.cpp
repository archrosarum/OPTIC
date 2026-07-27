#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"
#include "../nodes/node.h"

namespace OPTIC {
    Window::Window(std::string identifier) {
        this->identifier = identifier;
        finished = true;
        scale = 1;

        SDL_CreateWindowAndRenderer(
            this->title.c_str(),
            this->width,
            this->height,
            0,
            &(this->sdl_window),
            &(this->sdl_renderer)
        );
    }

    Window::~Window() {

    }


    // Tick
    void Window::tick() {
        SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
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

        if (finished) {
            SDL_SetWindowTitle(this->sdl_window, new_title.c_str());
        }

        return this;
    }

    std::string Window::get_title() {
        return this->title;
    }


    // Window size functions

    OPTIC::Window* Window::set_size(int new_width, int new_height) {
        width = new_width;
        height = new_height;

        if (finished) {
            SDL_SetWindowSize(this->sdl_window, new_width, new_height);
        }

        return this;
    }

    int Window::get_width() {
        return this->width;
    }

    int Window::get_height() {
        return this->height;
    }

    double Window::get_scale() {
        return this->scale;
    }


    // Window scale functions

    OPTIC::Window* Window::set_scale(double new_scale) {
        scale = new_scale;

        SDL_SetWindowSize(sdl_window, width * scale, height * scale);

        return this;
    }

    
    // Window internal pointer functions

    SDL_Window* Window::get_internal_window() { 
        return this->sdl_window;
    }

    SDL_Renderer* Window::get_internal_renderer() {
        return this->sdl_renderer;
    }
}
