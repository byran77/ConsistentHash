#include "consistentHash.h"
#include <sstream>

void consistentHash::init()
{
    for (int i = 0; i < m_node_num; i++) {
        for (int j = 0; j < m_virtual_num; j++) {
            std::stringstream node_id;
            node_id << i << "#" << j;
            uint32_t hash = m_hash->hash(node_id.str());
            m_server_nodes[hash] = i;
        }
    }
}


size_t consistentHash::getNodeIndex(const std::string& key)
{
    uint32_t hash = m_hash->hash(key);
    std::map<uint32_t, size_t>::iterator it = m_server_nodes.lower_bound(hash); 

    if (it == m_server_nodes.end()) {
        return m_server_nodes.begin()->second;
    }

    return it->second;
}  

void consistentHash::insert(const size_t index)
{
    for (int i = 0; i < m_virtual_num; i++) {
        std::stringstream node_id;
        node_id << index << "#" << i;
        uint32_t hash = m_hash->hash(node_id.str());
        m_server_nodes[hash] = index;
    }

    return ;
}

void consistentHash::remove(const size_t index)
{
    for (int i = 0; i < m_virtual_num; i++) {
        std::stringstream node_id;
        node_id << index << "#" << i;
        uint32_t hash = m_hash->hash(node_id.str());
        if (m_server_nodes.count(hash)) {
            m_server_nodes.erase(hash);
        }
        else {
            break;             
        }
    }

    return ;
}