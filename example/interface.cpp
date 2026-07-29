#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


// OPTIC Interface

using namespace OPTIC;

int main() {

    Runtime main;
    Window welcome;
    

    Rectangle rect_big;
        rect_big.size({1.5f, 1.5f});

    welcome.add_child(&rect_big);

    Rectangle rect_small;
        rect_small.size({1.5f, 1.5f});
        rect_small.set_fill_color({0, 255, 0});

    
    rect_big.add_child(&rect_small);
    
    main.add_child(&welcome);
    

    main.loop();
}
