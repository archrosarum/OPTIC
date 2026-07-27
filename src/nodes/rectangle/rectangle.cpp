#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"

namespace OPTIC {

    Rectangle::Rectangle(std::string identifier) : Node(identifier) {

    }

    Rectangle::~Rectangle() {

    }


    OPTIC::Rectangle*   Rectangle::set_position(double x, double y) {
        this->position = {x, y};

        return this;
    }

    OPTIC::Rectangle*   Rectangle::set_size(double width, double height) {
        this->size = {width, height};

        return this;
    }
}
