#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Rectangle : public OPTIC::Node {
    public:
        Rectangle(std::string identifier);
        ~Rectangle() override;

        void                tick() override;

        OPTIC::Rectangle*   set_position(double x, double y);
        OPTIC::Rectangle*   set_size(double width, double height);

    private:
        Coord               position;
        Coord               size;
    };
}