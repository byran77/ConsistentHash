#pragma once

#include <cstdint>

namespace HASH
{

    template<typename T>
    class Ihash
    {
    public:
        virtual uint32_t hash(const T& key) = 0;
    };

    template<typename T, typename C>
    Ihash<T>* createHash();
}

#include "hash_interface.inl"