#include "../shared.h"
#include "node.h"

namespace OPTIC {

    Node::Node() {
        this->position_ = {0.0f, 0.0f};
        this->anchor_ = {0.0f, 0.0f};
        this->size_ = {0.0f, 0.0f};

        this->visibility_ = SHOWN;

        this->window_ = nullptr;
        this->parent_ = nullptr;
    }

    Node::~Node() {

    }

    void Node::tick() {
        process();
        if (this->visibility_ == SHOWN) {
            render();
        }

        for (int i = 0; i < children_.size(); i++) {
            children_.at(i)->tick();
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

    Pixel Node::pixel_position() {
        return this->pixel_position_;
    }

    void Node::pixel_position(Pixel t_pixel_position) {
        this->pixel_position_ = t_pixel_position;
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

    void Node::pixel_dimentions(Pixel t_pixel_dimentions) {
        this->pixel_dimentions_ = t_pixel_dimentions;
    }

    Pixel Node::pixel_dimentions() {
        return this->pixel_dimentions_;
    }

    // Visibility

    void Node::hide() {
        this->visibility_ = HIDDEN;
    }

    void Node::show() {
        this->visibility_ = SHOWN;
    }

    // Family tree

    void Node::add_child(Node* child) {
        child->parent(this);
        child->window(this->window());
        children_.push_back(child);
    }

    void Node::parent(Node* t_parent) {
        this->parent_ = t_parent;
    }

    Node* Node::parent() {
        return this->parent_;
    }

    void Node::window(Window* t_window) {
        this->window_ = t_window;
    }

    Window* Node::window() {
        return this->window_;
    }
}
