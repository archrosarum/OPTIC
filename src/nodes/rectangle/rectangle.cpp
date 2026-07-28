#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"
#include "../../window/window.h"

namespace OPTIC {

    Rectangle::Rectangle(std::string identifier) : Node(identifier) {
        color = {128, 128, 128};
    }

    Rectangle::~Rectangle() {

    }

    void Rectangle::tick() {
        SDL_Renderer* internal_renderer = this->get_parent()->get_internal_renderer();

        SDL_SetRenderDrawColor(internal_renderer, color.red, color.green, color.blue, 255);

        SDL_FRect geometry;
        geometry.x = (float) position.x * get_parent()->get_scale();
        geometry.y = (float) position.y * get_parent()->get_scale();
        geometry.w = (float) size.x * get_parent()->get_scale();
        geometry.h = (float) size.y * get_parent()->get_scale();

        // 3. Draw the rectangle
        SDL_RenderFillRect(internal_renderer, &geometry);
    }

    OPTIC::Rectangle*   Rectangle::set_position(float x, float y) {
        this->position = {x, y};

        return this;
    }

    OPTIC::Rectangle*   Rectangle::set_size(float width, float height) {
        this->size = {width, height};

        return this;
    }

    OPTIC::Rectangle* Rectangle::set_color(OPTIC::Color new_color) {
        this->color = new_color;

        return this;
    }
}
