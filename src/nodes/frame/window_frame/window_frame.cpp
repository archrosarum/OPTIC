#include "../../../shared.h"
#include "../../node.h"
#include "window_frame.h"
#include "../../../window/window.h"

namespace OPTIC {

    WindowFrame::WindowFrame(Window* t_window) {
        this->window_ = t_window;
    }

    WindowFrame::~WindowFrame() {

    }



    void WindowFrame::handle_display_change() {

    }

    void WindowFrame::process() {

    }

    void WindowFrame::render() {

    }



    void WindowFrame::window(Window* t_window) {
        this->window_ = t_window;
    }

    Window* WindowFrame::window() {
        return this->window_;
    }

    Window* WindowFrame:: check_for_window() {
        return this->window_;
    }
}
