#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Runtime main;

    main.add_child(
        NEW_WINDOW("window")
        ->set_title("Window")
        ->set_size({480, 360})
        ->set_scale(1.5)
        ->set_background({255, 255, 255})
        ->add_child(NEW_TEXT("hello")
            ->set_text("Hello, world!")
            ->set_font("example/fonts/times_new_roman.ttf")
            ->set_justify(OPTIC::Text::Justify::CENTER)
        )
    );

    main.get_child("window")->get_child("hello")->as<OPTIC::Text>()->set_position(main.get_child("window")->get_center());

    while (main.isRunning()) {
        main.tick();
    }
}
