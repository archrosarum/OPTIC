#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"
#include "../nodes/node.h"
#include "../nodes/text/text.h"
#include "../nodes/frame/window_frame/window_frame.h"

namespace OPTIC {
    SDL_HitTestResult SDLCALL borderless_callback(SDL_Window* window, const SDL_Point* point, void* data) {
        if (point->y < 32) {
            return SDL_HITTEST_DRAGGABLE;
        } else {
            return SDL_HITTEST_NORMAL;
        }
    }

    Window::Window(Runtime* runtime) : frame_(this) {
        SDL_Init(SDL_INIT_VIDEO);
        
        set_size({480, 360});
        background = {255, 255, 255};
        scale = 1;
        has_text_support = false;

        SDL_CreateWindowAndRenderer(
            this->title.c_str(),
            this->size.width,
            this->size.height,
            SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_BORDERLESS,
            &(this->sdl_window),
            &(this->sdl_renderer)
        );

        handle_display_change();

        SDL_SetWindowHitTest(this->sdl_window, borderless_callback, NULL);
        SDL_SetRenderVSync(this->sdl_renderer, 1);

        frame_.window(this);
        frame_.rasterize_to_window(this);
        
        frame_.size({2.0f, 2.0f});
        frame_.position({0.0f, 0.0f});

        runtime->add_child(this);

        // Force compositer to draw the window
        SDL_ShowWindow(this->sdl_window);
        int w, h;
        SDL_GetWindowSize(this->sdl_window, &w, &h);
        SDL_SetWindowSize(this->sdl_window, w, h + 1);
        SDL_SyncWindow(this->sdl_window);
        SDL_SetWindowSize(this->sdl_window, w, h);
        SDL_SyncWindow(this->sdl_window);

        handle_display_change();
    }

    Window::~Window() {

    }

    void Window::handle_display_change() {
        SDL_GetWindowSizeInPixels(sdl_window, &this->pixel_width, &this->pixel_height);
        SDL_SetRenderLogicalPresentation(sdl_renderer, this->pixel_width, this->pixel_height, SDL_LOGICAL_PRESENTATION_DISABLED);

        this->aspect_ratio_ = (float)(this->pixel_width) / (float)(this->pixel_height);
        this->pixel_density = SDL_GetWindowPixelDensity(sdl_window);
        this->display_scale = SDL_GetWindowDisplayScale(sdl_window);

        for (int i = 0; i < children.size(); i++) {
            children.at(i)->handle_display_change();
        }

        pixel_dimentions_ = {this->pixel_width, this->pixel_height};

        frame_.rasterize_to_window(this);
    }

    void Window::bring_to_center() {
        SDL_SetWindowPosition(sdl_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }

    // Tick

    void Window::tick() {


        SDL_SetRenderDrawColor(sdl_renderer, background.red, background.green, background.blue, 255);
        SDL_RenderClear(sdl_renderer);

        frame_.tick();

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
        frame_.add_child(new_node);

        /*
        if (auto* node_cast = dynamic_cast<OPTIC::Text*>(new_node)) {
            try_text_support();
            node_cast->cache();
        } 
        */

        return this;
    }

    OPTIC::Window* Window::bind_event(Window::EventPointer event_ptr, void (*new_event)()) {
        this->*event_ptr = new_event;
        return this;
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

    float Window::aspect_ratio() {
        return this->aspect_ratio_;
    }

    Pixel Window::pixel_dimentions() {
        return this->pixel_dimentions_;
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

    OPTIC::Window* Window::set_display_scale(float new_scale) {
        this->display_scale = new_scale;

        return this;
    }

    float Window::get_display_scale() {
        return this->display_scale;
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


    // Window event bindings

    void Window::run_event(Window::EventPointer event_ptr) {
        auto func = this->*event_ptr;
        if (func != nullptr) {
            func();
        }
    }

    float Window::get_multiplier() {
        return scale * pixel_density;
    }

    Pixel Window::pixel_position(Normalized ndc) {
        Pixel return_px;

        return_px.x = (int)(((ndc.x + 1.0) * this->pixel_width) / 2.0);
        return_px.y = (int)(((1.0 - ndc.y) * this->pixel_height) / 2.0);

        return return_px;
    }

    Pixel Window::pixel_size(Normalized ndc) {
        Pixel return_px;

        std::abs(return_px.x = (int)((ndc.x * this->pixel_width) / 2.0));
        std::abs(return_px.y = (int)((ndc.y * this->pixel_height) / 2.0));

        return return_px;
    }
}
