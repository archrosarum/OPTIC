#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Rectangle : public Node {
    public:

        Rectangle();
        Rectangle(Node* parent);

        Rectangle(const Rectangle& original);

        Rectangle* derived_copy() const override {
            return new Rectangle(*this);
        }

        ~Rectangle() override;

        void                process() override;
        void                render() override;
        void                handle_display_change() override;

        OPTIC::Rectangle*   fill_color(OPTIC::Color new_color);
        Color               fill_color() const;

        OPTIC::Rectangle*   outline_color(OPTIC::Color new_color);
        Color               outline_color() const;

        OPTIC::Rectangle*   outline_thickness(float t_outline_thickness);
        float               outline_thickness() const;

        OPTIC::Rectangle*   filled(bool condition);
        bool                filled() const;

        OPTIC::Rectangle*   outlined(bool condition);
        bool                outlined() const;

    private:
        bool                filled_;
        bool                outlined_;

        OPTIC::Color        fill_color_;
        OPTIC::Color        outline_color_;

        float               outline_thickness_;
    };
}