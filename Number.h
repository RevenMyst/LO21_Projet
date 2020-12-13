#pragma once

#include <stdint-gcc.h>

namespace Number {
    bool isInt(double val)
    {
        return (uint64_t (val) - val == 0.0);
    }
};