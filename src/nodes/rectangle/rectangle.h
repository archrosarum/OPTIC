#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Rectangle : public OPTIC::Node {
    public:
        Rectangle();
        ~Rectangle() override;

        void                tick() override;
        void                handle_display_change() override;

        OPTIC::Rectangle*   set_position(float x, float y);
        OPTIC::Rectangle*   set_size(float width, float height);
        OPTIC::Rectangle*   set_fill_color(OPTIC::Color new_color);
        OPTIC::Rectangle*   set_outline_color(OPTIC::Color new_color);
        OPTIC::Rectangle*   set_outline_thickness(float new_outline_thickness);

        OPTIC::Rectangle*   filled(bool condition);
        OPTIC::Rectangle*   outlined(bool condition);



    private:
        bool                is_filled;
        bool                is_outlined;

        OPTIC::Color        fill_color;
        OPTIC::Color        outline_color;

        float               outline_thickness;

        Coord               position;
        Coord               size;
    };
}