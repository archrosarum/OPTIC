#pragma once

#include "../shared.h"

namespace OPTIC {

    class Measure {
    public:
        struct Normalized {
            float value;
        };

        struct Percentage {
            float value;
        };

        struct Pixel {
            int value;
        };

        Measure(Normalized value);
        Measure(Percentage value);
        Measure(Pixel value);
        ~Measure();

    private:
        Normalized          normalized_value_;
        Percentage          percentage_value_;
        Pixel               pixel_value_;
    };
}
