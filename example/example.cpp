#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Runtime main;

    main.AddChild((new OPTIC::Window("main"))
        ->SetTitle("Main window")
        ->SetSize(800, 600)
        ->SetScale(1.5)
        ->AddChild(OPTIC::Create::Element("element"))
    );

    while (main.isRunning()) {
        main.tick();
    }
}
