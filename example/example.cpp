#include "OPTIC/OPTIC.h"

int main() {
    OPTIC::Init();                                  // Cues OPTIC to set up the needed things for creating UI elements.

    OPTIC::Create::Window("main")                   // Creates a window and give it an identifier.
        ->SetTitle("Invisible name")                 // Gives the window a visible title.
        ->SetSize(800, 600);                          // Gives the window a size.

    OPTIC::Get::Window("main")                      // Once again gets the window.
        ->AddChild(OPTIC::Create::Element("element"));       // Creates an element and adds it to the gotten window.

    while (OPTIC::running) {                        // Establishes a loop dependent on the built in boolean.
        OPTIC::Tick();                                  // Provides an update to all created elements.
    }
}
