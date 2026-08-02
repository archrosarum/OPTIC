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

        bool                is_cursor_pressed();
        bool                was_cursor_pressed();

    private:
        std::vector<OPTIC::Window*> children;

        bool running;

        bool cursor_down;

        bool was_cursor_pressed_;
        bool is_cursor_pressed_;
    };
}
