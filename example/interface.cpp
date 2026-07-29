#include "OPTIC/OPTIC.h"

// Forward declaration of user defined events

void on_window_launch();


// OPTIC Interface

using namespace OPTIC;

int main() {

    Runtime main;

    Window welcome;
        welcome.bind_event(EVENT(event_open), on_window_launch);

    Text label;
        label.set_position(welcome.get_center());
        label.set_font_size(24);
        label.set_justify(OPTIC::Text::Justify::CENTER);
        label.set_text("Welcome!");
    
    Rectangle border;
        border.set_position(5, 5);
        border.filled(false);
        border.outlined(true);
        border.set_size(welcome.get_size().width - 10, welcome.get_size().height - 10);
        border.set_outline_thickness(2);

    welcome.add_child(&label);
    welcome.add_child(&border);
    main.add_child(&welcome);
    

    main.loop();
}
