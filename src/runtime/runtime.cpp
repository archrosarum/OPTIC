#include "../shared.h"
#include "runtime.h"


namespace OPTIC {

    Runtime::Runtime() {
        running = true;
        was_cursor_pressed_ = false;
        is_cursor_pressed_ = false;
        cursor_down = false;
        TTF_Init();
    }

    Runtime::~Runtime() {

    }

    void Runtime::loop() {
        while (isRunning()) {
            tick();
        }
    }

    bool Runtime::isRunning() {
        return running;
    }


    OPTIC::Runtime* Runtime::add_child(OPTIC::Window* new_window) {
        children.push_back(new_window);
        new_window->bring_to_center();
        new_window->run_event(&Window::event_open);

        return this;
    }

    bool Runtime::is_cursor_pressed() {
        return cursor_down;
    }

    bool Runtime::was_cursor_pressed() {

    }

    void Runtime::tick() {
        for (int i = 0; i < children.size(); i++) {
            OPTIC::Window* this_window = children.at(i);

            this_window->was_mouse_down = this_window->mouse_down;
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_WINDOW_MOVED) {
                SDL_Window* moved_window = SDL_GetWindowFromID(event.window.windowID);
                for (int i = 0; i < children.size(); i++) {
                    if (children.at(i)->get_internal_window() == moved_window) {
                        children.at(i)->handle_display_change();
                    }
                }
            }
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && event.button.button == SDL_BUTTON_LEFT) {
                SDL_Window* pressed_window = SDL_GetWindowFromID(event.button.windowID);
                for (int i = 0; i < children.size(); i++) {
                    if (children.at(i)->get_internal_window() == pressed_window) {
                        children.at(i)->mouse_down = true;
                    }
                }
            }
            if (event.type == SDL_EVENT_MOUSE_BUTTON_UP && event.button.button == SDL_BUTTON_LEFT) {
                SDL_Window* released_window = SDL_GetWindowFromID(event.button.windowID);
                for (int i = 0; i < children.size(); i++) {
                    if (children.at(i)->get_internal_window() == released_window) {
                        children.at(i)->mouse_down = false;
                    }
                }
            }
        }
        for (int i = 0; i < children.size(); i++) {
            OPTIC::Window* this_window = children.at(i);

            this_window->tick();
        }
    } 
}