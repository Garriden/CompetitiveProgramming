#include <iostream>
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

// g++ -std=c++20 0810FindDuplicates.cpp -o hola

// I just have 4KB of memory.

// Sort: O(n*log(n)) and then iterate O(n). QuickSort just uses log(n) memory.
// Time complexity: O(n*log(n))

// Map: O(n) but I need more memory.

// Vector<bool>: I have 32.000 integers. 32.000bits / 1byte(8bits) = 4KB. It fits!
// Time complexity: O(n)

int main()
{
    int n = 32000;
    std::vector<bool> found(n, false);
    std::vector<int> v(n, false);

    for(int ii = 0; ii < n; ++ii) {
        v[ii] = ii;
    }

    v[1000] = 24; // repeated number

    for(int ii = 0; ii < n; ++ii) {
        if(found[v[ii]]) {
            std::cout << "Repeated Element: " << v[ii] << std::endl;
            break;
        } else { // Still NOT found.
            found[v[ii]] = true;
        }
    }

    return 0;
}