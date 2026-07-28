#pragma once

#include "../shared.h"
#include "../nodes/node.h"


namespace OPTIC {

    class Window {
    public:
        struct Size {
            int width;
            int height;
        };

        Window(std::string identifier);
        ~Window();

        void                tick();

        OPTIC::Window*      hide();
        OPTIC::Window*      show();
        
        OPTIC::Window*      add_child(OPTIC::Node* new_node);
        OPTIC::Node*        get_child(std::string identifier);

        OPTIC::Window*      set_title(std::string new_title);
        std::string         get_title();

        OPTIC::Window*      set_size(Window::Size new_size);
        Window::Size        get_size();  
        OPTIC::Coord        get_center();                

        OPTIC::Window*      set_scale(float new_scale);
        float               get_scale();

        SDL_Window*         get_internal_window();
        SDL_Renderer*       get_internal_renderer();
        TTF_TextEngine*     get_internal_text_engine();

        float               get_pixel_density();

        OPTIC::Window*      set_background(OPTIC::Color new_background);
        OPTIC::Color        get_background();


        std::string         identifier;

    private:
        void                try_text_support();
        bool                has_text_support;

        bool                finished;

        std::vector<std::pair<std::string, OPTIC::Node*>> children;

        std::string         title;
        Window::Size        size;
        float               scale;

        OPTIC::Coord        center;

        OPTIC::Color        background;

        float               pixel_density;
        SDL_Window*         sdl_window;
        SDL_Renderer*       sdl_renderer;
        TTF_TextEngine*     ttf_engine;
    };
}
