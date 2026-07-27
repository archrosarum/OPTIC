#pragma once

#include "../root/root.h"

namespace OPTIC {

    inline bool running;
    inline Root* root;

    void Init();
    bool QuitOpportunity(bool condition);
    void Tick();
    void Quit();
}