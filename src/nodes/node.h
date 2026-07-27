#pragma once

#include "../shared.h"

namespace OPTIC {
    class Node {
    public:
        Node(std::string identifier);
        ~Node();

        void                hide();
        void                show();

        std::string         identifier;
        
    private:
        bool                hidden;
        bool                shown;
    };
}
