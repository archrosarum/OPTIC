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


    void Quit() {

    }
}
