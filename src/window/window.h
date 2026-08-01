#pragma once

#include "../shared.h"
#include "../nodes/node.h"
#include "../nodes/frame/window_frame/window_frame.h"

namespace OPTIC {

    class Runtime;

    class Window {
    public:
        using EventPointer = void (*Window::*)();

        struct Size {
            int width;
            int height;
        };

        Window(Runtime* runtime); 
        ~Window();
        
        void                tick();

        void                bring_to_center();

        void (*event_open)() = nullptr;
        void (*event_close)() = nullptr;
        void (*event_tick)() = nullptr;

        OPTIC::Window*      add_child(OPTIC::Node* new_node);
        OPTIC::Window*      bind_event(EventPointer event_ptr, void (*new_event)());

        void                handle_display_change();

        void                run_event(Window::EventPointer event_ptr);

        OPTIC::Window*      hide();
        OPTIC::Window*      show();
        

        OPTIC::Window*      set_title(std::string new_title);
        std::string         get_title();

        OPTIC::Window*      set_size(Window::Size new_size);
        Window::Size        get_size();  
        OPTIC::Coord        get_center();                

        OPTIC::Window*      set_scale(float new_scale);
        float               get_scale();

        OPTIC::Window*      set_display_scale(float new_scale);
        float               get_display_scale();

        float               get_multiplier();

        SDL_Window*         get_internal_window();
        SDL_Renderer*       get_internal_renderer();
        TTF_TextEngine*     get_internal_text_engine();

        float               get_pixel_density();

        OPTIC::Window*      set_background(OPTIC::Color new_background);
        OPTIC::Color        get_background();

        OPTIC::Window*      bind_to_event_init(void (*new_event_init)());
        void                run_event_init();

        Pixel               pixel_position(Normalized ndc);
        Pixel               pixel_size(Normalized ndc);

        Pixel               pixel_dimentions();

        float               aspect_ratio();           

    private:
        void                try_text_support();
        bool                has_text_support;

        std::vector<OPTIC::Node*> children;

        int pixel_width;
        int pixel_height;
        float aspect_ratio_;

        std::string         title;
        Window::Size        size;
        float               scale;
        float               display_scale;

        OPTIC::Coord        center;

        OPTIC::Color        background;

        Pixel               pixel_dimentions_;

        float               pixel_density;
        SDL_Window*         sdl_window;
        SDL_Renderer*       sdl_renderer;
        TTF_TextEngine*     ttf_engine;

        WindowFrame frame_;
    };
}
