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

// g++ -std=c++17 2116SumSwap.cpp -o hola

// Sort + Two pointers.
// Time complexity: O(n * log(n))

int main()
{
    std::vector<int> v1 = {4, 1, 2, 1, 1, 2};
    std::vector<int> v2 = {3, 6, 3, 3};

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    int firstPointer = 0;
    int secondPointer = 0;

    int sum1 = std::accumulate(v1.begin(), v1.end(), 0);
    int sum2 = std::accumulate(v2.begin(), v2.end(), 0);

    while(firstPointer < v1.size() || secondPointer < v2.size()) {
        if(sum1 - v1[firstPointer] + v2[secondPointer] == sum2 - v2[secondPointer] + v1[firstPointer]) {
            std::cout << v1[firstPointer] << "  " << v2[secondPointer] << std::endl;
            break;
        } else if(sum1 - v1[firstPointer] + v2[secondPointer] > sum2 - v2[secondPointer] + v1[firstPointer]) {
            ++firstPointer;
        } else {
            ++secondPointer;
        }
    }

    return 0;
}