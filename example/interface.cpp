#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


// OPTIC Interface

using namespace OPTIC;

int main() {

    Runtime main;

    Window window;
    main.add_child(&window);
    window.set_background({0, 0, 0});


    Rectangle rect;
    window.add_child(&rect);
    rect.size({1.75f, 1.75f});
    rect.position({-0.5f, 0.0f});
    rect.set_fill_color({255, 255, 255});

    Rectangle thing;
    rect.add_child(&thing);
    thing.size({0.5f, 1.0f});
    thing.anchor({-1.0f, 1.0f});
    thing.position({-1.0f, 1.0f});
    thing.set_fill_color({255, 0, 0});

    
    

    main.loop();
}
