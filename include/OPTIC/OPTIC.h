#pragma once

#define EVENT(member) &Window::member

#include "../src/datatypes.h"

struct Anchor {
    // one-dimentional
    static constexpr float MIDDLE = 0.0f;
    static constexpr float LEFT = -1.0f;
    static constexpr float RIGHT = 1.0f;

    // two-dimentional
    static constexpr OPTIC::Normalized CENTER = {0.0f, 0.0f};
    static constexpr OPTIC::Normalized TOP_LEFT = {-1.0f, 1.0f};
    static constexpr OPTIC::Normalized TOP_RIGHT = {1.0f, 1.0f};
    static constexpr OPTIC::Normalized BOTTOM_LEFT = {-1.0f, -1.0f};
    static constexpr OPTIC::Normalized BOTTOM_RIGHT = {1.0f, -1.0f};
};

// Runtime
#include "../src/runtime/runtime.h"
#define NEW_RUNTIME(...) (new OPTIC::Runtime(__VA_ARGS__))

// Window
#include "../src/window/window.h"
#define NEW_WINDOW(...) (new OPTIC::Window(__VA_ARGS__))

// Node
#include "../src/nodes/node.h"
#define NEW_NODE(...) (new OPTIC::Node( __VA_ARGS__))

/*


// Text (Node)
#include "../src/nodes/text/text.h"
#define NEW_TEXT(...) (new OPTIC::Text(__VA_ARGS__))

*/

// Rectangle (Node)
#include "../src/nodes/rectangle/rectangle.h"
#define NEW_RECTANGLE(...) (new OPTIC::Rectangle(__VA_ARGS__))




