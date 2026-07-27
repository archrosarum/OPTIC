#pragma once


// Runtime
#include "../src/runtime/runtime.h"
#define NEW_RUNTIME(...) (new OPTIC::Runtime(__VA_ARGS__))

// Window
#include "../src/window/window.h"
#define NEW_WINDOW(...) (new OPTIC::Window(__VA_ARGS__))

// Node
#include "../src/nodes/node.h"
#define NEW_NODE(...) (new OPTIC::Node(__VA_ARGS__) )

// Rectangle (Node)
#include "../src/nodes/rectangle/rectangle.h"
#define NEW_RECTANGLE(...) (new OPTIC::Rectangle(__VA_ARGS__) )

