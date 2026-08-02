#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void button_press(OPTIC::Node* self);
void button_release(OPTIC::Node* self);
void hover(OPTIC::Node* self);
void leave(OPTIC::Node* self);


// OPTIC Interface

using namespace OPTIC;

int main() {
    Text* hello_label = init<Text>()
      ->text("Hello, world!");

    Frame* button = init<Frame>()
      ->size({0.5f, 2.0f})
      ->add_child(init<Rectangle>()
        ->filled(false)
        ->outlined(true))
      ->add_child(init<Text>()
        ->text("Button"));

    Frame* buttons = init<Frame>()
      ->size({1.0f, 0.2f})
      ->position({0.0f, -0.75f})
      ->add_child(button->copy_as<Frame>()->position({-1.0f, 0.0f}))
      ->add_child(button->copy_as<Frame>()->position({1.0f, 0.0f}));

    Runtime main;
    Window* window = init<Window>(&main)
      ->add_child(hello_label)
      ->add_child(buttons);

    main.loop();
}
