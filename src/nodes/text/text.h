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

        OPTIC::Text* text(std::string t_text);
        OPTIC::Text* font(std::string t_font_path);
        OPTIC::Text* font_size(float t_font_size);
        OPTIC::Text* font_color(OPTIC::Color t_font_color);

    private:
        void load_font();

        OPTIC::Color    font_color_;
        std::string     font_path_;
        float           font_size_;
        std::string     text_;

        TTF_Font*        font_ = nullptr;
        TTF_Text*        text_cache_ = nullptr;
    };
}