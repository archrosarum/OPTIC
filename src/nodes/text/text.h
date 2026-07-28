#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Text : public OPTIC::Node {
    public:
        enum class Justify{
            LEFT,
            RIGHT,
            CENTER,
        };

        Text(std::string identifier);
        ~Text() override;

        void                tick() override;

        void                cache();
        void                load_font();

        OPTIC::Text*        set_font(std::string font_path);
        OPTIC::Text*        set_text(std::string new_text);
        OPTIC::Text*        set_justify(Text::Justify new_justify);
        OPTIC::Text*        set_position(OPTIC::Coord new_position);
        OPTIC::Text*        set_font_size(float new_font_size);
        OPTIC::Text*        set_color(OPTIC::Color new_color);

    private:
        TTF_Text*           text_cache;

        std::string         text;

        TTF_Font*           font;
        std::string         font_path;
        Text::Justify       justify;

        Coord               position;
        float               font_size;
        OPTIC::Color        color;
    };
}