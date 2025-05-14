#include <iostream>
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

// g++ -std=c++20 0310SearchInRotatedArray.cpp -o hola

// BF: Iterate.
// Time complexity: O(n)

// Binary Search:
// Time complexity: O(log(n))

int Search(std::vector<int> &v, int x)
{
    int index = -1;
    int firstValue = v[0];
    int lastValue = v[v.size() - 1];
    int left = 0;
    int right = v.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;
        //std::cout << "mid: " << mid << std::endl;
        if(x == v[mid]) {
            return mid;
        } else if(x == lastValue) {
            return v.size() - 1;
        } else if(x == firstValue) {
            return 0;
        } else if(x < lastValue) {
            if(v[mid] > lastValue) { // Already dipped.
                left = mid + 1;
            } else {
                if(v[mid] < x) {
                    left = mid + 1;
                } else { // v[mid] > x
                    right = mid - 1;
                }
            }
        } else { // (x >= lastValue)
            if(v[mid] < firstValue) { // Already dipped.
                right = mid -1;
            } else {
                if(v[mid] < x) {
                    left = mid + 1;
                } else { // v[mid] > x
                    right = mid - 1;
                }
            }
        }

    }

    return index;
}


int main()
{
    std::vector<int> v1 = {15,16,19,20,25,1,3,4,5,7,10,14};
    std::vector<int> v2 = {3,4,5,7,10,14,15,16,19,20,1,2};

    int solutionV1 = 8;
    int solutionV2 = 10;
    int solutionV3 = 1;

    std::cout << (solutionV1 == Search(v1, 5)) << std::endl;
    std::cout << (solutionV2 == Search(v2, 1)) << std::endl;
    std::cout << (solutionV3 == Search(v1, 16)) << std::endl;

    return 0;
}