#include "../shared.h"
#include "runtime.h"
#include "../root/root.h"

namespace OPTIC {

    void Init() {
        running = true;
        root = new Root();
    }

    bool QuitOpportunity(bool condition) {
        if (condition) {
            Quit();
            return false;
        } else {
            return true;
        }
    }

    void Tick() {
        static bool first_call = true;
        if (first_call) {
            first_call = false;

            for (int i = 0; i < root->children.size(); i++) {
                OPTIC::Window* this_window = root->children.at(i).second;
                
                SDL_CreateWindowAndRenderer(
                    this_window->title.c_str(),
                    this_window->width,
                    this_window->height,
                    0,
                    &(this_window->sdl_window),
                    &(this_window->sdl_renderer)
                );
            }
        } else {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                    running = false;
                }
            }

            for (int i = 0; i < root->children.size(); i++) {
                OPTIC::Window* this_window = root->children.at(i).second;
            }
        }
    }


    void Quit() {

    }
}
