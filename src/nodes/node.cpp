#include "../shared.h"
#include "node.h"

namespace OPTIC {
    Node::Node() {
        this->position_ = {0.0f, 0.0f};
        this->anchor_ = {0.0f, 0.0f};
        this->size_ = {0.0f, 0.0f};

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

    // Positioning

    void Node::position(Normalized t_position) {
        this->position_ = t_position;
    }

    Normalized Node::position() {
        return this->position_;
    }

    // Anchoring

    void Node::anchor(Normalized t_anchor) {
        this->anchor_ = t_anchor;
    }

    Normalized Node::anchor() {
        return this->anchor_;
    }

    // Sizing

    void Node::size(Normalized t_size) {
        this->size_ = t_size;
    }

    Normalized Node::size() {
        return this->size_;
    }

    // Visibility

    void Node::hide() {
        hidden = true;
        shown = false;
    }

    void Node::show() {
        hidden = false;
        shown = true;
    }
}
