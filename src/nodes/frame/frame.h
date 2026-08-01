#pragma once

#include "../../shared.h"
#include "../node.h"

namespace OPTIC {

    class Frame : public Node {
    public:
        using Node::Node;

        Frame();
         Node* derived_copy() const override { return new Frame(*this); }
         
        ~Frame() override;

        void                process() override;
        void                render() override;
        void                handle_display_change() override;

    private:
        
    };
}