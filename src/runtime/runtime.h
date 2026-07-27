#pragma once

#include "../window/window.h"


namespace OPTIC {
    class Runtime {
    public:
        Runtime();
        ~Runtime();

        void                tick();
        bool                isRunning();

        OPTIC::Runtime*     add_child(OPTIC::Window* new_window);
        OPTIC::Window*      get_child(std::string identifier);

    private:
        std::vector<std::pair<std::string, OPTIC::Window*>> children;

        bool running;
    };
}
