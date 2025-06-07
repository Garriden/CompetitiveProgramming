#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>

// g++ -std=c++20 0308MagicIndex.cpp -o hola

bool BinarySearch(const std::vector<int> &v, int left, int right) {
    while(left <= right) {
        int mid = (left + right) / 2;

        // Watch if its a repeated number.
        int itL = mid;
        while(itL > 0 && v[itL] == v[mid]) {
            if(v[itL] == (itL + 1)) {
                return true;
            }
            --itL;
        }
        int itR = mid;
        while((itR < v.size() - 1) && v[itR] == v[mid]) {
            if(v[itR] == (itR + 1)) {
                return true;
            }
            --itR;
        }

        if(v[mid] == (mid + 1)) {
            return true;
        } else if(v[mid] < (itL + 1)) {
            left = mid + 1;
        } else if(v[mid] > (itR + 1)) {
            right = mid - 1;
        }
    }
    return false;
}

int main() {


    std::vector<int> v{1,21,31,41,51,61,71,81,91};

    std::cout << "Found: " << BinarySearch(v, 0, v.size()) << std::endl;

    std::vector<int> v2{1,1,31,41,51,61,71,81,91};

    std::cout << "NOT distinct -> Found: " << BinarySearch(v2, 0, v2.size()) << std::endl;

    return 0;
}