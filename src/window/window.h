#pragma once


#include "../shared.h"

#include "../elements/element.h"


namespace OPTIC {

    class Window {
    public:
        Window();
        ~Window();

        void Build();
        OPTIC::Window* Add(OPTIC::Element* new_element);
        
        OPTIC::Window* ModifyTitle(std::string new_title);
        std::string title;

        OPTIC::Window* ModifySize(int new_width, int new_height);
        int width;
        int height;

        std::vector<std::pair<std::string, OPTIC::Element*>> children;

        SDL_Window* sdl_window;
        SDL_Renderer* sdl_renderer;

    private:
        bool finished = false;
    };
}


namespace OPTIC::Create {

    OPTIC::Window* Window(std::string identifier);
}


namespace OPTIC::Get {
    OPTIC::Window* Window(std::string identifier);
}
