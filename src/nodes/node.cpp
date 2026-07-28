#include "../shared.h"
#include "node.h"

namespace OPTIC {
    Node::Node(std::string identifier) {
        this->parent = nullptr;
        this->identifier = identifier;

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
        // to be overwritten
    }

    void Node::hide() {
        hidden = true;
        shown = false;
    }

    void Node::show() {
        hidden = false;
        shown = true;
    }
}
