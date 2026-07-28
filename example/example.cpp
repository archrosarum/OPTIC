#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Runtime main;

    main.add_child(
        NEW_WINDOW("window")
        ->set_title("Window")
        ->set_size(480, 360)
        ->set_scale(1)
        ->set_background({255, 255, 255})
        ->add_child(NEW_TEXT("hello")
            ->load_font("example/fonts/times_new_roman.ttf")
        )
    );

    while (main.isRunning()) {
        main.tick();
    }
}
