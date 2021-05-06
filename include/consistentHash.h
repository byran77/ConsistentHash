#pragma once

#include "hash_interface.h"
#include "murmurHash3.h"
#include <cstdint>
#include <map>
#include <string>

using namespace HASH;

class consistentHash
{
public:
    consistentHash(size_t node_num, size_t virtual_num): \
        m_node_num(node_num), m_virtual_num(virtual_num) {
            m_hash = createHash<std::string, murmurHash3>();
        }
    ~consistentHash() { m_server_nodes.clear(); }

    void init();

    //get the node index of a certain record
    size_t getNodeIndex(const std::string& key);    
    //add a new node
    void insert(const size_t index);
    //delete a existed node
    void remove(const size_t index);

private:
    std::map<uint32_t, size_t> m_server_nodes;   //the virtual hashspace
    size_t m_node_num;                           //the number of nodes
    size_t m_virtual_num;                        //the number of virtual nodes per node

    Ihash<std::string>* m_hash;                  //the type of hash algorithm
};