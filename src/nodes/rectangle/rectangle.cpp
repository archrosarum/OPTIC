#include "../../shared.h"
#include "../node.h"
#include "rectangle.h"
#include "../../window/window.h"

namespace OPTIC {

    // constructor and destructor

    Rectangle::Rectangle() : Node() {
        this->size({0.25f, 0.25f});

        filled_ = true;
        outlined_ = false;
        outline_thickness_ = 1;

        fill_color_ = {255, 0, 0};
        outline_color_ = {0, 0, 0};
    }

    Rectangle::Rectangle(Node* parent) : Node() {
        this->size({0.25f, 0.25f});

        filled_ = true;
        outlined_ = false;
        outline_thickness_ = 1;

        fill_color_ = {255, 0, 0};
        outline_color_ = {0, 0, 0};

        this->is_child_of(parent);
    }

Rectangle::Rectangle(const Rectangle& original) : Node(original)
{
    fill_color_ = original.fill_color();
    outline_color_ = original.outline_color();
    outline_thickness_ = original.outline_thickness();
    filled_ = original.filled();
    outlined_ = original.outlined();
}

    Rectangle::~Rectangle() {

    }

    // functions overriden as required by base class

    void Rectangle::handle_display_change() {
        
    }

    void Rectangle::process() {

    }

    void Rectangle::render() {
        Pixel parent_position_px;
        Pixel parent_size_px;

        parent_position_px = this->parent()->position_px();
        parent_size_px = this->parent()->size_px();

        Window* parent = this->check_for_window();
        if (parent == nullptr) {
            std::cout << "no parent";
            return;
        }
        SDL_Renderer* internal_renderer = parent->get_internal_renderer();

        SDL_FRect geometry;

        geometry.w = (float)((size().x / 2.0) * parent_size_px.x);
        geometry.h = (float)((size().y / 2.0) * parent_size_px.y);

        float center_x = parent_position_px.x + (float)(((position().x + 1.0) * parent_size_px.x) / 2.0);
        float center_y = parent_position_px.y + (float)(((1.0 - position().y) * parent_size_px.y) / 2.0);

        geometry.x = center_x - (((this->anchor().x + 1.0f) / 2.0f) * geometry.w);
        geometry.y = center_y - (((1.0f - this->anchor().y) / 2.0f) * geometry.h);

        size_px({(int)geometry.w, (int)geometry.h});
        position_px({(int)geometry.x, (int)geometry.y});

        if (filled_) {
            SDL_SetRenderDrawColor(internal_renderer, fill_color_.red, fill_color_.green, fill_color_.blue, 255);
            SDL_RenderFillRect(internal_renderer, &geometry);
        }
        
        if (outlined_) {
            
            SDL_SetRenderDrawColor(internal_renderer, outline_color_.red, outline_color_.green, outline_color_.blue, 255);
            
            SDL_FRect top = { geometry.x, geometry.y, geometry.w, outline_thickness_ * parent->get_multiplier()};
            SDL_RenderFillRect(internal_renderer, &top);

            SDL_FRect bottom = { geometry.x, geometry.y + geometry.h - outline_thickness_ * parent->get_multiplier(), geometry.w, outline_thickness_ };
            SDL_RenderFillRect(internal_renderer, &bottom);

            SDL_FRect left = { geometry.x, geometry.y, outline_thickness_ * parent->get_multiplier(), geometry.h };
            SDL_RenderFillRect(internal_renderer, &left);

            SDL_FRect right = { geometry.x + geometry.w - outline_thickness_, geometry.y, outline_thickness_ * parent->get_multiplier(), geometry.h };
            SDL_RenderFillRect(internal_renderer, &right);
            
        }
        
    }

    // functions unique to this derived class

    OPTIC::Rectangle* Rectangle::fill_color(OPTIC::Color new_color) {
        this->fill_color_ = new_color;

        return this;
    }

    Color Rectangle::fill_color() const {
        return this->fill_color_;
    }

    OPTIC::Rectangle* Rectangle::outline_color(OPTIC::Color new_color) {
        this->outline_color_ = new_color;

        return this;
    }

    Color Rectangle::outline_color() const {
        return this->outline_color_;
    }

    OPTIC::Rectangle* Rectangle::outline_thickness(float t_outline_thickness) {
        this->outline_thickness_ = t_outline_thickness;

        return this;
    }

    float Rectangle::outline_thickness() const {
        return this->outline_thickness_;
    }


    OPTIC::Rectangle* Rectangle::filled(bool condition) {
        this->filled_ = condition;

        return this;
    }

    bool Rectangle::filled() const {
        return this->filled_;
    }

    OPTIC::Rectangle* Rectangle::outlined(bool condition) {
        this->outlined_ = condition;

        return this;
    }

    bool Rectangle::outlined() const {
        return this->outlined_;
    }
}
