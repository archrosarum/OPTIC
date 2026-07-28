#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Text : public OPTIC::Node {
    public:
        Text(std::string identifier);
        ~Text() override;

        void                tick() override;
        void                cache();

        OPTIC::Text*        set_text(std::string new_text);
        OPTIC::Text*        load_font(std::string font_path);
        OPTIC::Text*        set_position(double x, double y);
        OPTIC::Text*        set_size(double width, double height);
        OPTIC::Text*        set_color(OPTIC::Color new_color);

    private:
        TTF_Text*           text_cache;

        std::string         text;
        TTF_Font*           font;

        Coord               position;
        Coord               size;
        OPTIC::Color        color;
    };
}