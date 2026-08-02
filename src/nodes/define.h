#pragma once

#include "../shared.h"
#include "OPTIC/OPTIC.h"

namespace OPTIC {

    template <typename T, typename... Args>
    T* init(Args&&... args) {
        return new T(std::forward<Args>(args)...);
    }
}
