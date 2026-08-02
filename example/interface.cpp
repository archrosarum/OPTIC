#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void button_press(OPTIC::Node* self);
void button_release(OPTIC::Node* self);
void hover(OPTIC::Node* self);
void leave(OPTIC::Node* self);


// OPTIC Interface

using namespace OPTIC;

int main() {

     Frame button;
            button.size({1.0f, 0.25f});
            button.position({0.f, -0.5f});
            Rectangle little(&button);
                little.bind_event(little.on_cursor_press, button_press);
                little.bind_event(little.on_cursor_release, button_release);
                little.bind_event(little.on_curser_enter, hover);
                little.bind_event(little.on_curser_leave, leave);
                little.fill_color({255, 255, 0});
                little.outlined(true);
                little.outline_thickness(2);
                little.size({2.0f, 2.0f});
                Text label(&little);
                    label.set_text("Button");
                    label.set_color({0, 0, 0});
                    label.set_font_size(24);
                    label.position({0.0f, 0.0f});

    Rectangle rect;
        rect.size({1.75f, 1.75f});
        rect.position({0.0f, 0.0f});
        rect.fill_color({0, 255, 255});
        rect.outlined(true);
        rect.outline_thickness(2);
        Text greeting(&rect);
                greeting.position({0.0f, 0.5f});
                greeting.set_font_size(70);
                greeting.set_color({0, 0, 0});
                greeting.set_text("Hello!");
        button.is_child_of(&rect);
       
    Runtime main;

    Window window(&main);
        window.set_background({255, 0, 255});
        Rectangle* rect_copy = static_cast<Rectangle*>(rect.copy());
        window.add_child(rect_copy);

    main.loop();
}
