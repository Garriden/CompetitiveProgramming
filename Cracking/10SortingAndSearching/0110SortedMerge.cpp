#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 0110SortedMerge.cpp -o hola

// Auxiliar vector or copy the first half of the vector a into the second half. O(n)
//  Then just Two Pointers comparation. O(n)

// Or Two pointers decremental from back to front.

void Merge(std::vector<int> &a, std::vector<int> &b)
{
    int n = a.size();

    // Copy the first half of the vector a into the second half. O(n)
    for(int ii = 0; ii < n/2; ++ii) {
        a[n/2 + ii] = a[ii];
    }

    // Two Pointers comparation. O(n)
    int ai = n/2;
    int bi = 0;
    int index = 0;
    while(index < n && ai < n && bi < n/2) {
        if(a[ai] < b[bi]) {
            a[index] = a[ai++];
        } else {
            a[index] = b[bi++];
        }
        ++index;
    }

    while(ai < n) {
        a[index] = a[ai++];
    }

    while(bi < n/2) {
        a[index] = b[bi++];
    }

}

int main()
{
    std::vector<int> a = {1, 2, 4, 5, 7, 8, 10, 30, 60, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int> b = {3, 6, 9, 10, 20, 40, 50, 70, 80, 100};

    Merge(a, b);

    for(int ii = 0; ii < a.size(); ++ii) {
        std::cout << a[ii] << " ";
    } std::cout << std::endl;

    return 0;
}