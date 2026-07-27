#pragma once

#include "../shared.h"

namespace OPTIC {
    class Element {
    public:
        Element();
        ~Element();

        std::string identifier;
        
    private:

    };
}

namespace OPTIC::Create {
    OPTIC::Element* Element(std::string identifier);
}
