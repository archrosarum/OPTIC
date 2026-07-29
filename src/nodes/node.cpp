#include "../shared.h"
#include "node.h"

namespace OPTIC {
    Node::Node() {
        this->parent = nullptr;
        this->shown = true;

        SDL_Init(SDL_INIT_VIDEO);
    }

    Node::~Node() {

    }

    void Node::set_parent(OPTIC::Window* new_parent) {
        this->parent = new_parent;
    }

    OPTIC::Window* Node::get_parent() {
        return this->parent;
    }

    void Node::tick() {
        process();
        if (shown) {
            render();
        }
    }

    void Node::process() {
        // meant to be overwritten
    }

    void Node::render() {
        // meant to be overwritten
    }

    void Node::handle_display_change() {
        // meant to be overwritten
    }

    void                position(Normalized t_position);    // mutator
    Normalized          position();                         // accessor

    void                anchor(Normalized t_anchor);        // mutator
    Normalized          anchor();                           // accessor


    void Node::hide() {
        hidden = true;
        shown = false;
    }

    void Node::show() {
        hidden = false;
        shown = true;
    }
}
