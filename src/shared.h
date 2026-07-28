#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <utility>
#include <string>


// Custom coordinate struct

namespace OPTIC {
    struct Coord {
        double x;
        double y;
    };

    struct Color {
        int red;
        int green;
        int blue;
    };
}
