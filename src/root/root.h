#pragma once

#include "../shared.h"
#include "../window/window.h"

class Root {
public:
    Root();
    ~Root();
    std::vector<std::pair<std::string, OPTIC::Window*>> children;
private:
    
};


