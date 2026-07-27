#include "OPTIC/OPTIC.h"

int main() {

    OPTIC::Init();                                  // Cues OPTIC to set up the needed things for creating UI elements.

    OPTIC::Create::Window("main")                   // Creates a window and give it an identifier.
        ->ModifyTitle("Invisible name")                 // Gives the window a visible title.
        ->ModifySize(800, 600)                          // Gives the window a size.
        ->Build();                                      // Engages SDL3 to generate a window based on the created object.
        
    OPTIC::Get::Window("main")                      // Gets the created window after creating it.
        ->ModifyTitle("Main");                          // Modifies it's title, and automatically adjusts SDL3 window.

    OPTIC::Get::Window("main")                      // Once again gets the window.
        ->Add(OPTIC::Create::Element("element"));       // Creates an element and adds it to the gotten window.

    while (OPTIC::running) {                        // Establishes a loop dependent on the built in boolean.
        OPTIC::Tick();                                  // Provides an update to all created elements.
    }
}
