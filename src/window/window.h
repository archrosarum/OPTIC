#pragma once

#include "../shared.h"
#include "../nodes/node.h"


namespace OPTIC {

    class Window {
    public:
        Window(std::string identifier);
        ~Window();

        std::string         identifier;

        OPTIC::Window*      Hide();
        OPTIC::Window*      Show();
        
        OPTIC::Window*      AddChild(OPTIC::Node* new_node);
        OPTIC::Node*        GetChild(std::string identifier);

        OPTIC::Window*      SetTitle(std::string new_title);
        std::string         GetTitle();

        OPTIC::Window*      SetSize(int new_width, int new_height);
        int                 GetWidth();
        int                 GetHeight();

        OPTIC::Window*      SetScale(double new_scale);
        double              GetScale();

    private:
        bool                finished;

        std::vector<std::pair<std::string, OPTIC::Node*>> children;

        std::string         title;
        int                 width;
        int                 height;
        double              scale;
        
        SDL_Window*         sdl_window;
        SDL_Renderer*       sdl_renderer;
    };
}
