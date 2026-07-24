#pragma once

#include "../shared.h"
#include "../window/window.h"

class Root {
public:
    Root();
    ~Root();
private:
    std::vector<Window> Children;
};