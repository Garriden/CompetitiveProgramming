#include <iostream>
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

// g++ -std=c++20 1110PeaksAndValleys.cpp -o hola

// Sort + Two Pointers: Max - min. Doesn't work properly.
// Time complexity: O(n *log(n))

// Sort + iterate: Switch every pair and will satisfy a peak.
// Time complexity: O(n *log(n))

// Exists an algorithm without sorting that accomplish O(n).
// Do the same swap but without Ordering the vector.
// Comparing all three values and jumping two iterations.

void MinMax(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;

    while(left <= right) {
        std::cout << v[right--];
        if(left <= right) {
            std::cout << v[left++];
        }
    } std::cout << std::endl;
}

void Switch(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());

    for(int ii = 1; ii < v.size() - 1; ii += 2) {
        int aux = v[ii];
        v[ii] = v[ii+1];
        v[ii+1] = aux;
    }

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii];
    } std::cout << std::endl;
}

void SwitchUnsorted(std::vector<int>& v) {
    for(int ii = 1; ii < v.size() - 1; ii += 2) {
        int biggestIndex = ii;

        if(v[ii - 1] > v[biggestIndex]) {
            biggestIndex = ii - 1;
        } else if(v[ii + 1] > v[biggestIndex]) {
            biggestIndex = ii + 1;
        }

        // Swap.
        int aux = v[ii];
        v[ii] = v[biggestIndex];
        v[biggestIndex] = aux;
    }

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii];
    } std::cout << std::endl;
}

int main()
{
    std::vector<int> v{5, 3, 1, 2, 3};
    SwitchUnsorted(v);

    return 0;
}