#include <iostream>
#include <OPTIC/OPTIC.h>

void foo1(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({255, 255, 0});
}

void foo2(OPTIC::Node* self) {
    OPTIC::Rectangle* rect = static_cast<OPTIC::Rectangle*>(self);
    rect->fill_color({225, 225, 0});
    std::cout << "Pressed!" << std::endl;
}