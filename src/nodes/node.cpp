#include "../shared.h"
#include "node.h"

namespace OPTIC {
    Node::Node(std::string identifier) {
        this->identifier = identifier;
    }

    Node::~Node() {

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
