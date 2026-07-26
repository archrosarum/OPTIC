#include "OPTIC/OPTIC.h"

int main() {

    OPTIC::Init();  // Cues OPTIC to set up the needed things for creating UI elements.

    OPTIC::Create::Window("main")       // Creates a window and give it an identifier.
        ->ModifyTitle("Invisible name")     // Gives the window a visible title.
        ->ModifySize(800, 600);             // Gives the window a size.

    OPTIC::Get::Window("main")          // Gets the created window after creating it.
        ->ModifyTitle("Main");              // Modifies it's title.

    while (OPTIC::running) {
        OPTIC::Tick();
    }
}
