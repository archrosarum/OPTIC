#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Text : public Node {
    public:

        Text();
        Text(Node* parent);

        Text(const Text& original);
        Text* derived_copy() const override {
            return new Text(*this);
        }

        ~Text() override;

        void process() override;
        void render() override;
        void handle_display_change() override;

        void cache();

        OPTIC::Text* set_text(std::string new_text);
        OPTIC::Text* set_font(std::string font_path);
        OPTIC::Text* set_font_size(float new_font_size);
        OPTIC::Text* set_color(OPTIC::Color new_color);

    private:
        void load_font();

        OPTIC::Color    color_;
        std::string     font_path_;
        float           font_size_;
        std::string     text_;

        TTF_Font*        font_ = nullptr;
        TTF_Text*        text_cache_ = nullptr;
    };
}