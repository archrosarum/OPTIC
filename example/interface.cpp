#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void button_press(OPTIC::Node* self);
void button_release(OPTIC::Node* self);
void hover(OPTIC::Node* self);
void leave(OPTIC::Node* self);


// OPTIC Interface

using namespace OPTIC;

int main() {
    Runtime main;

    Text* hello_label = init<Text>()
      ->text("Hello, world!");

    Window* window = init<Window>(&main)
      ->add_child(hello_label->copy_as<Text>());

    main.loop();
}
