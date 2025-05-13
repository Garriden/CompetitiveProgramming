#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 BinarySearch.cpp -o hola

int BinarySearch(std::vector<int> &v, int x)
{
    int left = 0;
    int right = v.size() -1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(v[mid] == x) {
            return mid;
        } else if(v[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int n = 10;
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Found at index: " << BinarySearch(v, 2) << std::endl;

    return 0;
}