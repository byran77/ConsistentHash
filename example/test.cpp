#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <sstream>
#include "consistentHash.h"

using namespace std;

int main()
{
    int sample_num = 2000;

    int node_num = 10;
    int virtual_num = 10;

    consistentHash* p_hash = new consistentHash(node_num, virtual_num);
    p_hash->init();
    map<int, int> count;
    
    vector<int> sample(sample_num, 0);

    random_device generator;
    uniform_int_distribution<int> distribution(0, 100000);
    for (int& n: sample) {
        n = distribution(generator);
        stringstream ss;
        ss << n;

        int index = p_hash->getNodeIndex(ss.str());
        count[index]++;
    }

    for (auto it = count.begin(); it != count.end(); it++) {
        cout << "Record in node[" << it->first << "]: " << it->second << endl;
    }

    return 0;
}