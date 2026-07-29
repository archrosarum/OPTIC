#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


// OPTIC Interface

using namespace OPTIC;

int main() {

    Runtime main;

    Window welcome;
        welcome.bind_event(EVENT(event_open), on_window_launch);

    Rectangle rect2;
    welcome.add_child(&rect2);
    rect2.size({rect2.size().x / welcome.aspect_ratio(), rect2.size().y});

    
    
    main.add_child(&welcome);
    

    main.loop();
}
