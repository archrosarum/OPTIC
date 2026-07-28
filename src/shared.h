#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

#include <iostream>
#include <vector>
#include <utility>
#include <string>


// Custom coordinate struct

namespace OPTIC {
    struct Coord {
        float x;
        float y;
    };

    struct Color {
        int red;
        int green;
        int blue;
    };
}
