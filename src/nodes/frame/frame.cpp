#include "../../shared.h"
#include "../node.h"
#include "frame.h"
#include "../../window/window.h"

namespace OPTIC {

    Frame::Frame() {

    }

    Frame::~Frame() {

    }



    void Frame::handle_display_change() {
        Node::handle_display_change();
    }

    void Frame::process() {

    }

    void Frame::render() {
        if (parent() == nullptr) {
            return;
        }

        Pixel parent_position_px = parent()->position_px();
        Pixel parent_size_px = parent()->size_px();

        float w = (float)((size().x / 2.0) * parent_size_px.x);
        float h = (float)((size().y / 2.0) * parent_size_px.y);

        float center_x = parent_position_px.x + (float)(((position().x + 1.0) * parent_size_px.x) / 2.0);
        float center_y = parent_position_px.y + (float)(((1.0 - position().y) * parent_size_px.y) / 2.0);

        float x = center_x - (((this->anchor().x + 1.0f) / 2.0f) * w);
        float y = center_y - (((1.0f - this->anchor().y) / 2.0f) * h);

        size_px({(int)w, (int)h});
        position_px({(int)x, (int)y});
    }
}
