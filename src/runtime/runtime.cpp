#include "../shared.h"
#include "runtime.h"


namespace OPTIC {

    Runtime::Runtime() {
        running = true;
        TTF_Init();
    }

    Runtime::~Runtime() {

    }


    bool Runtime::isRunning() {
        return running;
    }


    OPTIC::Runtime* Runtime::add_child(OPTIC::Window* new_window) {
        children.push_back(std::pair<std::string, OPTIC::Window*>(new_window->identifier, new_window));

        return this;
    }

    OPTIC::Window* Runtime::get_child(std::string identifier) {
        for (int i = 0; i < children.size(); i++) {
            if (children.at(i).first == identifier) {
                return children.at(i).second;
            }
        }

        return NULL;
    }


    void Runtime::tick() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        for (int i = 0; i < children.size(); i++) {
            OPTIC::Window* this_window = children.at(i).second;

            this_window->tick();
        }
    }
}
