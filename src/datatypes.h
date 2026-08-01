#pragma once


namespace OPTIC {

    struct Normalized {
        float x;
        float y;
    };

    struct Logical {
        int x;
        int y;
    };

    struct Pixel {
        int x;
        int y;
    };

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

    enum Visibility {
        SHOWN = 1,
        HIDDEN = 0
    };

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
