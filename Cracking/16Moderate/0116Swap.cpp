#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0116Swap.cpp -o hola

// Fi

int main()
{
    int n = 24;
    std::vector<int> v = {25, 10, 5, 1};
    
    // Swap
    v[0] -= v[1];
    v[1] = v[0] + v[1] + v[1];

    //std::cout << v[0] << " " << v[1] << std::endl;

    v[0] = (v[1] - v[0]) / 2;
    v[1] = (v[1] - v[0]);

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    }std::cout << std::endl;
    return 0;
}