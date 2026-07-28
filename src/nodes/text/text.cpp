#include "../../shared.h"
#include "../node.h"
#include "text.h"
#include "../../window/window.h"

namespace OPTIC {

    Text::Text(std::string identifier) : Node(identifier) {
        color = {0, 0, 0};
        text = "Text";
    }

    Text::~Text() {

    }

    void Text::tick() {
        TTF_TextEngine* internal_text_engine = this->get_parent()->get_internal_text_engine();

        TTF_DrawRendererText(text_cache, (float) position.x, (float) position.y);
    }

    void Text::cache() {
        TTF_TextEngine* internal_text_engine = this->get_parent()->get_internal_text_engine();

        load_font();
        text_cache = TTF_CreateText(internal_text_engine, font, text.c_str(), 0);
        TTF_SetTextColor(text_cache, color.red, color.green, color.blue, 255);
    }


    OPTIC::Text* Text::set_text(std::string new_text) {
        this->text = new_text;

        return this;
    }

    OPTIC::Text* Text::set_font(std::string font_path) {
        this->font_path = font_path;

        if (get_parent() != nullptr) {
            load_font();
        }

        return this;
    }

    void Text::load_font() {
        this->font = TTF_OpenFont(font_path.c_str(), (float)((float)16 * get_parent()->get_scale() * get_parent()->get_pixel_density()));

        if (!font) {
            SDL_Log("Failed to load font: %s", SDL_GetError());
        }
    }


    OPTIC::Text*   Text::set_position(double x, double y) {
        this->position = {x, y};

        return this;
    }

    OPTIC::Text*   Text::set_size(double width, double height) {
        this->size = {width, height};

        return this;
    }

    OPTIC::Text* Text::set_color(OPTIC::Color new_color) {
        this->color = new_color;

        return this;
    }
}
