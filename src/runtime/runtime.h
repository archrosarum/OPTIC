#pragma once

#include "../window/window.h"


namespace OPTIC {
    class Runtime {
    public:
        Runtime();
        ~Runtime();

        void                tick();
        bool                isRunning();

        OPTIC::Runtime*     AddChild(OPTIC::Window* new_window);
        OPTIC::Window*      GetChild(std::string identifier);

    private:
        std::vector<std::pair<std::string, OPTIC::Window*>> children;

        bool running;
    };
}
