#include "../../shared.h"
#include "../node.h"
#include "text.h"
#include "../../window/window.h"

namespace OPTIC {

    Text::Text() : Node() {
        font_color_ = {0, 0, 0};
        font_path_ = "src/fonts/times_new_roman.ttf";
        font_size_ = 16;
        text_ = "Text";
    }

    Text::Text(Node* parent) : Node() {
        font_color_ = {0, 0, 0};
        font_path_ = "src/fonts/times_new_roman.ttf";
        font_size_ = 16;
        text_ = "Text";

        this->is_child_of(parent);
    }

    Text::Text(const Text& original) : Node(original)
    {
        font_color_ = original.font_color_;
        font_path_ = original.font_path_;
        font_size_ = original.font_size_;
        text_ = original.text_;
        // font_ / text_cache_ intentionally NOT copied — see note below
    }

    Text::~Text() {

    }

    void Text::process() {

    }

    void Text::render() {
        Window* window = check_for_window();
        if (window == nullptr) {
            return;
        }

        if (parent() == nullptr) {
            return;
        }

        if (font_ == nullptr) {
            load_font();
        }
        if (text_cache_ == nullptr) {
            cache();
        }

        int width, height;
        TTF_GetStringSize(font_, text_.c_str(), 0, &width, &height);

        Pixel parent_position_px = parent()->position_px();
        Pixel parent_size_px = parent()->size_px();

        float center_x = parent_position_px.x + (float)(((position().x + 1.0) * parent_size_px.x) / 2.0);
        float center_y = parent_position_px.y + (float)(((1.0 - position().y) * parent_size_px.y) / 2.0);

        float draw_x = center_x - (((this->anchor().x + 1.0f) / 2.0f) * width);
        float draw_y = center_y - (((1.0f - this->anchor().y) / 2.0f) * height);

        size_px({width, height});
        position_px({(int)draw_x, (int)draw_y});

        TTF_DrawRendererText(text_cache_, draw_x, draw_y);
    }

    void Text::handle_display_change() {
        cache();
        Node::handle_display_change();
    }

    void Text::cache() {
        Window* window = check_for_window();
        if (window == nullptr) {
            return;
        }

        TTF_TextEngine* internal_text_engine = window->get_internal_text_engine();

        load_font();

        if (text_cache_ != nullptr) {
            TTF_DestroyText(text_cache_);
        }

        text_cache_ = TTF_CreateText(internal_text_engine, font_, text_.c_str(), 0);
        TTF_SetTextColor(text_cache_, font_color_.red, font_color_.green, font_color_.blue, 255);
    }

    OPTIC::Text* Text::text(std::string t_text) {
        this->text_ = t_text;
        cache();
        return this;
    }

    OPTIC::Text* Text::font(std::string t_font_path) {
        this->font_path_ = t_font_path;

        if (check_for_window() != nullptr) {
            load_font();
        }

        return this;
    }

    void Text::load_font() {
        Window* window = check_for_window();
        if (window == nullptr) {
            return;
        }

        if (font_ != nullptr) {
            TTF_CloseFont(font_);
        }

        font_ = TTF_OpenFont(font_path_.c_str(), (float)(font_size_ * window->get_multiplier()));

        if (!font_) {
            SDL_Log("Failed to load font: %s", SDL_GetError());
        }
    }

    OPTIC::Text* Text::font_size(float t_font_size) {
        this->font_size_ = t_font_size;
        return this;
    }

    OPTIC::Text* Text::font_color(OPTIC::Color t_font_color) {
        this->font_color_ = t_font_color;
        return this;
    }
}