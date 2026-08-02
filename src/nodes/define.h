#pragma once

#include "../shared.h"
#include "OPTIC/OPTIC.h"

namespace OPTIC {
    template <typename T, typename... Args>
    T* init(Args&&... args) {
        T* n = new T(std::forward<Args>(args)...);
        return n;
    }
}
