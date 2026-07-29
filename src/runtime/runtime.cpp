#include "../shared.h"
#include "runtime.h"


namespace OPTIC {

    Runtime::Runtime() {
        running = true;
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

    void Runtime::tick() {
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
        }
        for (int i = 0; i < children.size(); i++) {
            OPTIC::Window* this_window = children.at(i);

            this_window->tick();
        }
    } 
}