#pragma once

#include "../shared.h"

namespace OPTIC {

    class Window {
    public:
        Window();
        ~Window();
        
        OPTIC::Window* ModifyTitle(std::string new_title);
        std::string title;

        OPTIC::Window* ModifySize(int new_width, int new_height);
        int width;
        int height;

        SDL_Window* sdl_window;
        SDL_Renderer* sdl_renderer;
    private:
        
    };
}


namespace OPTIC::Create {

    OPTIC::Window* Window(std::string identifier);
}


namespace OPTIC::Get {
    OPTIC::Window* Window(std::string identifier);
}
