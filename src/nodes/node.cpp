#include "../shared.h"
#include "node.h"
#include "../window/window.h"
#include "frame/window_frame/window_frame.h"

namespace OPTIC {

    Node::Node() {
        this->position_ = {0.0f, 0.0f};
        this->anchor_ = {0.0f, 0.0f};
        this->size_ = {0.0f, 0.0f};

        this->visibility_ = SHOWN;

        this->parent_ = nullptr;
    }

    Node::Node(Node* t_parent) {
        this->position_ = {0.0f, 0.0f};
        this->anchor_ = {0.0f, 0.0f};
        this->size_ = {0.0f, 0.0f};

        this->visibility_ = SHOWN;

        this->parent_ = t_parent;

        t_parent->add_child(this);
    }

    Node* Node::copy() {
        Node* node_copy = derived_copy();
        node_copy->parent_ = nullptr;
        node_copy->children_.clear();

        for (Node* child : this->children_) {
            Node* child_copy = child->copy();
            child_copy->parent_ = node_copy;
            node_copy->children_.push_back(child_copy);
        }

        return node_copy;
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

    // Family tree

    void Node::add_child(Node* child) {
        child->parent(this);
        children_.push_back(child);

        if (check_for_window() != nullptr) {
            child->rasterize_to_window(check_for_window());
        }
    }

    void Node::is_child_of(Node* t_parent) {
        parent(t_parent);
        t_parent->add_child(this);
    }

    void Node::parent(Node* t_parent) {
        this->parent_ = t_parent;
    }

    Node* Node::parent() {
        return this->parent_;
    }

    // Positioning

    void Node::position(Normalized t_position) {
        this->position_ = t_position;
    }

    Normalized Node::position() {
        return this->position_;
    }

    Pixel Node::position_px() {
        return this->position_px_;
    }

    void Node::position_px(Pixel t_position_px) {
        this->position_px_ = t_position_px;
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

    void Node::size_px(Pixel t_size_px) {
        this->size_px_ = t_size_px;
    }

    Pixel Node::size_px() {
        return this->size_px_;
    }

    // Visibility

    void Node::hide() {
        this->visibility_ = HIDDEN;
    }

    void Node::show() {
        this->visibility_ = SHOWN;
    }

    // Windowing

    Window* Node::check_for_window() {
        if (this->parent_ != nullptr) {
            return this->parent_->check_for_window();
        } else {
            return nullptr;
        }
    }

    void Node::rasterize_to_window(Window* window) {
        if (window != nullptr) {
            this->size_px_ = {
                (int)((size_.x * window->pixel_dimentions().x) / 2.0),
                (int)((size_.y * window->pixel_dimentions().y) / 2.0)
            };

            this->position_px_ = {
                (int)((position_.x * window->pixel_dimentions().x) / 2.0),
                (int)((position_.y * window->pixel_dimentions().y) / 2.0)
            };
        }

        for (int i = 0; i < children_.size(); i++) {
            children_.at(i)->rasterize_to_window(check_for_window());
        }
    }

}
