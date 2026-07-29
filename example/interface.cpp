#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


// OPTIC Interface

int main() {
    OPTIC::Runtime main;

    main.add_child(
        NEW_WINDOW("window")
        ->bind_to_event_init(on_window_launch)
        ->set_title("Window")
        ->set_size({480, 360})
        ->set_scale(1.5)
        ->set_background({255, 255, 255})
        ->add_child(NEW_TEXT("hello")
            ->set_text("Hello, world!")
            ->set_font("example/fonts/times_new_roman.ttf")
            ->set_font_size(20)
            ->set_justify(OPTIC::Text::Justify::CENTER)
        )
        ->add_child(NEW_RECTANGLE("border")
            ->outlined(true)
            ->filled(false)
            ->set_size(470, 350)
            ->set_position(5, 5)
        )
    );

    main.get_child("window")->get_child("hello")->as<OPTIC::Text>()->set_position(main.get_child("window")->get_center());

    while (main.isRunning()) {
        main.tick();
    }
}
