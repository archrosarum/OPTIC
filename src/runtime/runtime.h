#pragma once

#include "../window/window.h"


namespace OPTIC {
    class Runtime {
    public:
        Runtime();
        ~Runtime();

        void                loop();

        void                tick();
        bool                isRunning();

        OPTIC::Runtime*     add_child(OPTIC::Window* new_window);

    private:
        std::vector<OPTIC::Window*> children;

        bool running;
    };
}
