#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"
#include "../nodes/node.h"

namespace OPTIC {
    Window::Window(std::string identifier) {
        this->identifier = identifier;
        finished = true;
        scale = 1;

        SDL_CreateWindowAndRenderer(
            this->title.c_str(),
            this->width,
            this->height,
            0,
            &(this->sdl_window),
            &(this->sdl_renderer)
        );
    }

    Window::~Window() {

    }


    // Window hide and unhide

    OPTIC::Window* Window::Hide() {
        SDL_HideWindow(this->sdl_window);

        return this;
    } 

    OPTIC::Window* Window::Show() {
        SDL_ShowWindow(this->sdl_window);

        return this;
    } 


    // Window children functions

    OPTIC::Window* Window::AddChild(OPTIC::Node* new_node) {
        children.push_back(std::pair<std::string, OPTIC::Node*>(new_node->identifier, new_node));

        return this;
    }

    OPTIC::Node* Window::GetChild(std::string identifier) {
        for (int i = 0; i < children.size(); i++) {
            if (children.at(i).first == identifier) {
                return children.at(i).second;
            }
        }

        return NULL;
    }


    // Window title functions

    OPTIC::Window* Window::SetTitle(std::string new_title) {
        title = new_title;

        if (finished) {
            SDL_SetWindowTitle(this->sdl_window, new_title.c_str());
        }

        return this;
    }

    std::string Window::GetTitle() {
        return this->title;
    }


    // Window size functions

    OPTIC::Window* Window::SetSize(int new_width, int new_height) {
        width = new_width;
        height = new_height;

        if (finished) {
            SDL_SetWindowSize(this->sdl_window, new_width, new_height);
        }

        return this;
    }

    int Window::GetWidth() {
        return this->width;
    }

    int Window::GetHeight() {
        return this->height;
    }


    // Window scale functions

    OPTIC::Window* Window::SetScale(double new_scale) {
        scale = new_scale;

        SDL_SetWindowSize(sdl_window, width * scale, height * scale);

        return this;
    }
}
