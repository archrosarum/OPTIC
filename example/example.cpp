#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Runtime main;

    main.add_child(
        NEW_WINDOW("window")
        ->set_title("Window")
        ->set_size(480, 360)
        ->set_scale(1.5)
        ->set_background({255, 255, 255})
        ->add_child(
            NEW_RECTANGLE("bar")
            ->set_size(64, 600)
            ->set_position(0, 0)
            ->set_color({220, 220, 220}))
        ->add_child(
            NEW_RECTANGLE("button1")
            ->set_size(48, 48)
            ->set_position(8, 8)
            ->set_color({200, 200, 200}))
    );

    while (main.isRunning()) {
        main.tick();
    }
}
