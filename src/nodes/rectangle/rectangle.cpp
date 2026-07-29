#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"
#include "../../window/window.h"

namespace OPTIC {

    Rectangle::Rectangle() : Node() {
        is_filled = true;
        is_outlined = false;
        outline_thickness = 1;

        fill_color = {255, 0, 0};
        outline_color = {0, 0, 0};
    }

    Rectangle::~Rectangle() {

    }

    void Rectangle::tick() {
        SDL_Renderer* internal_renderer = this->get_parent()->get_internal_renderer();

        SDL_FRect geometry;
        geometry.x = (float) position.x * get_parent()->get_multiplier();
        geometry.y = (float) position.y * get_parent()->get_multiplier();
        geometry.w = (float) size.x * get_parent()->get_multiplier();
        geometry.h = (float) size.y * get_parent()->get_multiplier();

        if (is_filled) {
            SDL_SetRenderDrawColor(internal_renderer, fill_color.red, fill_color.green, fill_color.blue, 255);
            SDL_RenderFillRect(internal_renderer, &geometry);
        }
        
        if (is_outlined) {
            SDL_SetRenderDrawColor(internal_renderer, outline_color.red, outline_color.green, outline_color.blue, 255);
            
            SDL_FRect top = { geometry.x, geometry.y, geometry.w, outline_thickness * get_parent()->get_multiplier()};
            SDL_RenderFillRect(internal_renderer, &top);

            SDL_FRect bottom = { geometry.x, geometry.y + geometry.h - outline_thickness * get_parent()->get_multiplier(), geometry.w, outline_thickness };
            SDL_RenderFillRect(internal_renderer, &bottom);

            SDL_FRect left = { geometry.x, geometry.y, outline_thickness * get_parent()->get_multiplier(), geometry.h };
            SDL_RenderFillRect(internal_renderer, &left);

            SDL_FRect right = { geometry.x + geometry.w - outline_thickness, geometry.y, outline_thickness * get_parent()->get_multiplier(), geometry.h };
            SDL_RenderFillRect(internal_renderer, &right);
        }
    }

    void Rectangle::handle_display_change() {
        
    }

    OPTIC::Rectangle*   Rectangle::set_position(float x, float y) {
        this->position = {x, y};

        return this;
    }

    OPTIC::Rectangle*   Rectangle::set_size(float width, float height) {
        this->size = {width, height};

        return this;
    }

    OPTIC::Rectangle* Rectangle::set_fill_color(OPTIC::Color new_color) {
        this->fill_color = new_color;

        return this;
    }

    OPTIC::Rectangle* Rectangle::set_outline_color(OPTIC::Color new_color) {
        this->outline_color = new_color;

        return this;
    }

    OPTIC::Rectangle* Rectangle::set_outline_thickness(float new_outline_thickness) {
        this->outline_thickness = new_outline_thickness;

        return this;
    }


    OPTIC::Rectangle* Rectangle::filled(bool condition) {
        this->is_filled = condition;

        return this;
    }

    OPTIC::Rectangle* Rectangle::outlined(bool condition) {
        this->is_outlined = condition;

        return this;
    }
}
