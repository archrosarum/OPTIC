#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


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
            little.fill_color({255, 255, 0});
            little.outlined(true);
            little.outline_thickness(2);
            little.size({1.5f, 1.5f});
            little.anchor({-1.0f, 1.0f});
            little.position({-1.0f, 1.0f});
    
    Runtime main;

    Window window(&main);
        window.set_background({255, 0, 255});
        Rectangle* rect_copy = static_cast<Rectangle*>(rect.copy());
        window.add_child(rect_copy);

    main.loop();
}
