#include "../../shared.h"
#include "../node.h"
#include "text.h"
#include "../../window/window.h"

namespace OPTIC {

    Text::Text(std::string identifier) : Node(identifier) {
        color = {0, 0, 0};
        font_size = 11;
        text = "Text";
    }

    Text::~Text() {

    }

    void Text::tick() {
        TTF_TextEngine* internal_text_engine = this->get_parent()->get_internal_text_engine();

        int width, height;

        TTF_GetStringSize(font, text.c_str(), 0, &width, &height);

        float draw_x = (float) (position.x * get_parent()->get_scale() * get_parent()->get_pixel_density());
        float draw_y = (float) (position.y * get_parent()->get_scale() * get_parent()->get_pixel_density());

        if (justify == Text::Justify::CENTER) {
            draw_x -= width / 2;
            draw_y -= height / 2;
        }

        if (justify == Text::Justify::RIGHT) {
            draw_x += width / 2;
            draw_y += height / 2;
        }

        TTF_DrawRendererText(text_cache, draw_x, draw_y);
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
        this->font = TTF_OpenFont(font_path.c_str(), (float)(font_size * get_parent()->get_scale() * get_parent()->get_pixel_density()));

        if (!font) {
            SDL_Log("Failed to load font: %s", SDL_GetError());
        }
    }

    OPTIC::Text* Text::set_justify(Text::Justify new_justify) {
        this->justify = new_justify;

        return this;
    }


    OPTIC::Text*   Text::set_position(OPTIC::Coord new_position) {
        this->position = {new_position.x, new_position.y};

        return this;
    }

    OPTIC::Text*   Text::set_font_size(float new_font_size) {
        this->font_size = new_font_size;

        return this;
    }

    OPTIC::Text* Text::set_color(OPTIC::Color new_color) {
        this->color = new_color;

        return this;
    }
}
