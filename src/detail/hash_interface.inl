#pragma once

#include "murmurHash3.h"

namespace HASH
{
    template<typename T, typename C>
    Ihash<T>* createHash()
    {
        return new C;
    }
}