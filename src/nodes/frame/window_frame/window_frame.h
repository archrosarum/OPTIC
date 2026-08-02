#pragma once

#include "../../../shared.h"
#include "../../node.h"
#include "../frame.h"

namespace OPTIC {

    class WindowFrame : public Frame {
    public:
        WindowFrame(Window* t_window);
        Node* derived_copy() const override { return new Frame(*this); }
        ~WindowFrame() override;

        void handle_display_change() override;
        void process() override;                          
        void render() override;

        void window(Window* t_window);
        Window* window();

        Window* check_for_window() override;

    private:
        Window* window_;
    };
}