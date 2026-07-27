#pragma once

#include "../shared.h"
#include "../elements/element.h"


namespace OPTIC {
    class Window {
    public:
        Window();
        ~Window();

        void Build();
        
        OPTIC::Window*      AddChild(OPTIC::Element* new_element);
        OPTIC::Element*     GetChild(std::string identifier);

        OPTIC::Window*      SetTitle(std::string new_title);
        std::string         GetTitle();

        OPTIC::Window*      SetSize(int new_width, int new_height);
        int                 GetWidth();
        int                 GetHeight();

    private:
        std::string         identifier;
        bool                finished;

        std::vector<std::pair<std::string, OPTIC::Element*>> children;

        std::string         title;
        int                 width;
        int                 height;
        
        SDL_Window*         sdl_window;
        SDL_Renderer*       sdl_renderer;
    };
}


namespace OPTIC::Create {

    OPTIC::Window* Window(std::string identifier);
}


namespace OPTIC::Get {
    OPTIC::Window* Window(std::string identifier);
}
