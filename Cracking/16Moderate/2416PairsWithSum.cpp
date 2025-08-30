#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <numeric> // Required for std::accumulate

// g++ -std=c++17 2416PairsWithSum.cpp -o hola

// 1. For each element, search other elements in the vector.
//  Time complexity: O(n^2)

// 2. Sort + Two Pointers.
//  Time complexity: O(n * log(n))

// 3. Iterate vector + build hashMap -> key: res - element, value = element.
//    Iterate the vector again checking if the element exists in hashMap as value.
//  Time complexity: O(n)

int main()
{
    int resultValue = 50;
    std::vector<int> v = {24, 27, 82, 26, 99, 3456, 367, 5788, 9869};
    std::unordered_map<int, int> diffElement; // key = resultValue - element, value = element.

    // Iterate vector + build hashMap
    for(int ii = 0; ii < v.size(); ++ii) {
        diffElement[resultValue - v[ii]] = v[ii];
    }

    // Iterate the vector again checking if the element exists in hashMap as value.
    for(int ii = 0; ii < v.size(); ++ii) {
        if(diffElement.count(v[ii])) {
            std::cout << diffElement[v[ii]] << " " << v[ii] << std::endl;
            break;
        }
    }

    return 0;
}