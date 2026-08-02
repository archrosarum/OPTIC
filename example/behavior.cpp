#include <iostream>
#include <OPTIC/OPTIC.h>

void button_press(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({225, 225, 0});
    std::cout << "Pressed!" << std::endl;
}

void button_release(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({255, 255, 0});
}

void hover(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({240, 240, 0});
}

void leave(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({255, 255, 0});
}

