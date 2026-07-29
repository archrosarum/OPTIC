#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"
#include "../../window/window.h"

namespace OPTIC {

    // constructor and destructor

    Rectangle::Rectangle() : Node() {
        this->size({0.25f, 0.25f});

        is_filled = true;
        is_outlined = false;
        outline_thickness = 1;

        fill_color = {255, 0, 0};
        outline_color = {0, 0, 0};
    }

    Rectangle::~Rectangle() {

    }

    // functions overriden as required by base class

    void Rectangle::handle_display_change() {
        
    }

    void Rectangle::process() {

    }

    void Rectangle::render() {
        SDL_Renderer* internal_renderer = this->get_parent()->get_internal_renderer();
        Window* parent = this->get_parent();

        SDL_FRect geometry;

        geometry.w = (float) parent->pixel_size(size()).x;
        geometry.h = (float) parent->pixel_size(size()).y;

        geometry.x = (float) parent->pixel_position(position()).x - ((this->anchor().x + 1.0) * (geometry.w / 2.0));
        geometry.y = (float) parent->pixel_position(position()).y - ((1.0 - this->anchor().y) * (geometry.h / 2.0));

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

    // functions unique to this derived class

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
