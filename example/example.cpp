#include "OPTIC/OPTIC.h"

int main() {

    OPTIC::Init();

    OPTIC::Create::Window("main")
        ->ModifyTitle("Main")
        ->ModifySize(800, 600);

    while (OPTIC::running) {
        OPTIC::Tick();
    }
}
