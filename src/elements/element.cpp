#include "../shared.h"
#include "element.h"

namespace OPTIC {
    Element::Element() {

    }

    Element::~Element() {

    }
}

namespace OPTIC::Create {
    OPTIC::Element* Element(std::string identifier) {
        OPTIC::Element* new_element = new OPTIC::Element();
        new_element->identifier = identifier;

        return new_element;
    }
}
