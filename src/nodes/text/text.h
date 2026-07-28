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
        void                load_font();

        OPTIC::Text*        set_font(std::string font_path);
        OPTIC::Text*        set_text(std::string new_text);
        OPTIC::Text*        set_position(double x, double y);
        OPTIC::Text*        set_size(double width, double height);
        OPTIC::Text*        set_color(OPTIC::Color new_color);

    private:
        TTF_Text*           text_cache;

        std::string         text;

        TTF_Font*           font;
        std::string         font_path;

        Coord               position;
        Coord               size;
        OPTIC::Color        color;
    };
}