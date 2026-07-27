#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Runtime main;

    main.add_child
    (
        NEW_WINDOW("window")
        ->set_title("Window")
        ->set_size(800, 600)
        ->set_scale(1.5)
        ->add_child
        (
            NEW_RECTANGLE("rectangle")
            ->set_size(100, 100)
            ->set_position(100, 100)
        )
    );

    while (main.isRunning()) {
        main.tick();
    }
}
