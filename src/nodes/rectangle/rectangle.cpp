#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"
#include "../../window/window.h"

namespace OPTIC {

    Rectangle::Rectangle(std::string identifier) : Node(identifier) {

    }

    Rectangle::~Rectangle() {

    }

    void Rectangle::tick() {
        SDL_Renderer* internal_renderer = this->get_parent()->get_internal_renderer();

        SDL_SetRenderDrawColor(internal_renderer, 255, 255, 255, 255);

        SDL_FRect geometry;
        geometry.x = (float) position.x;
        geometry.y = (float) position.y;
        geometry.w = (float) size.x;
        geometry.h = (float) size.y;

        // 3. Draw the rectangle
        SDL_RenderFillRect(internal_renderer, &geometry);
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
