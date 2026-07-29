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
        Pixel parent_pixel_position;
        Pixel parent_pixel_dimentions;

        if (this->parent() == nullptr && this->window() != nullptr) {
            parent_pixel_position = {0, 0};
            parent_pixel_dimentions = this->window()->pixel_dimentions();
        } else if (this->parent() != nullptr && this->window() != nullptr) {
            parent_pixel_position = this->parent()->pixel_position();
            parent_pixel_dimentions = this->parent()->pixel_dimentions();
        } else {
            parent_pixel_position = {0, 0};
            parent_pixel_dimentions = {0, 0};
        }

        SDL_Renderer* internal_renderer = this->window()->get_internal_renderer();
        Window* parent = this->window();

        SDL_FRect geometry;

        geometry.w = (float)((size().x / 2.0) * parent_pixel_dimentions.x);
        geometry.h = (float)((size().y / 2.0) * parent_pixel_dimentions.y);

        float center_x = parent_pixel_position.x + (float)(((position().x + 1.0) * parent_pixel_dimentions.x) / 2.0);
        float center_y = parent_pixel_position.y + (float)(((1.0 - position().y) * parent_pixel_dimentions.y) / 2.0);

        geometry.x = center_x - ((this->anchor().x + 1.0f) * (geometry.w / 2.0f));
        geometry.y = center_y - ((1.0f - this->anchor().y) * (geometry.h / 2.0f));

        pixel_dimentions({(int)geometry.w, (int)geometry.h});
        pixel_position({(int)geometry.x, (int)geometry.y});

        if (is_filled) {
            SDL_SetRenderDrawColor(internal_renderer, fill_color.red, fill_color.green, fill_color.blue, 255);
            SDL_RenderFillRect(internal_renderer, &geometry);
        }
        
        if (is_outlined) {
            
            SDL_SetRenderDrawColor(internal_renderer, outline_color.red, outline_color.green, outline_color.blue, 255);
            
            SDL_FRect top = { geometry.x, geometry.y, geometry.w, outline_thickness * window()->get_multiplier()};
            SDL_RenderFillRect(internal_renderer, &top);

            SDL_FRect bottom = { geometry.x, geometry.y + geometry.h - outline_thickness * window()->get_multiplier(), geometry.w, outline_thickness };
            SDL_RenderFillRect(internal_renderer, &bottom);

            SDL_FRect left = { geometry.x, geometry.y, outline_thickness * window()->get_multiplier(), geometry.h };
            SDL_RenderFillRect(internal_renderer, &left);

            SDL_FRect right = { geometry.x + geometry.w - outline_thickness, geometry.y, outline_thickness * window()->get_multiplier(), geometry.h };
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
