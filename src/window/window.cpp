#include "../shared.h"
#include "window.h"
#include "../runtime/runtime.h"

namespace OPTIC {

    Window::Window() {

    }

    Window::~Window() {
        
    }


    OPTIC::Window* Window::ModifyTitle(std::string new_title) {
        title = new_title;
        
        return this;
    }

    OPTIC::Window* Window::ModifySize(int new_width, int new_height) {
        width = new_width;
        height = new_height;

        return this;
    }
}


namespace OPTIC::Create {

    OPTIC::Window* Window(std::string identifier) {
        OPTIC::Window* new_window = new OPTIC::Window();
        root->children.push_back(std::pair<std::string, OPTIC::Window*>(identifier, new_window));
        return new_window;
    }
}
