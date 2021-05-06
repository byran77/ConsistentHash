#pragma once

#include "hash_interface.h"
#include <string>

namespace HASH
{

class murmurHash3 : public Ihash<std::string>
{
public:
    uint32_t hash(const std::string& key) override;
private:
    uint32_t murmur3(const char* key, uint32_t len, uint32_t seed = 17);
};

}