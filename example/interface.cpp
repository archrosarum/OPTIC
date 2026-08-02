#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void foo1(OPTIC::Node* self);
void foo2(OPTIC::Node* self);


// OPTIC Interface

using namespace OPTIC;

int main() {

    Rectangle rect;
        rect.size({1.75f, 1.75f});
        rect.position({0.0f, 0.0f});
        rect.fill_color({0, 255, 255});
        rect.outlined(true);
        rect.outline_thickness(2);
        Rectangle little(&rect);
            little.bind_event(little.on_cursor_press, foo2);
            little.bind_event(little.on_cursor_release, foo1);
            little.fill_color({255, 255, 0});
            little.outlined(true);
            little.outline_thickness(2);
            little.size({0.75f, 0.25f});
            little.anchor({0.0f, 0.0f});
            little.position({0.0f, -0.5f});
            Text label(&little);
                label.set_text("Hello");
                label.set_color({0, 0, 0});
                label.set_font_size(24);
                label.position({0.0f, 0.0f});

    Runtime main;

    Window window(&main);
        window.set_background({255, 0, 255});
        Rectangle* rect_copy = static_cast<Rectangle*>(rect.copy());
        window.add_child(rect_copy);

    main.loop();
}
