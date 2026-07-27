#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"
#include "../elements/element.h"

namespace OPTIC {
    Window::Window() {
        finished = false;
    }

    Window::~Window() {

    }

    void Window::Build() {
        finished = true;

        SDL_CreateWindowAndRenderer(
            this->title.c_str(),
            this->width,
            this->height,
            0,
            &(this->sdl_window),
            &(this->sdl_renderer)
        );
    }


    // Window children functions
    
    OPTIC::Window* Window::AddChild(OPTIC::Element* new_element) {
        children.push_back(std::pair<std::string, OPTIC::Element*>(new_element->identifier, new_element));

        return this;
    }

    OPTIC::Element* Window::GetChild(std::string identifier) {
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
}


namespace OPTIC::Create {

    OPTIC::Window* Window(std::string identifier) {
        OPTIC::Window* new_window = new OPTIC::Window();

        root->children.push_back(std::pair<std::string, OPTIC::Window*>(identifier, new_window));

        return new_window;
    }
}


namespace OPTIC::Get {

    OPTIC::Window* Window(std::string identifier) {
        for (int i = 0; i < root->children.size(); i++) {
            if (root->children.at(i).first == identifier) {
                return root->children.at(i).second;
            }
        }

        return NULL;
    }
}
