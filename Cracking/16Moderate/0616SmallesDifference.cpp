#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0616SmallesDifference.cpp -o hola

// 1, 2, 3, 11, 15
void BinarySearch(int x, const std::vector<int> &v, int left, int right, std::pair<int,int> &res)
{
    if(right < left) {
        //std::cout << "res1: " << res.first << "  / res2: " << res.second << std::endl;
        return;
    }

    int mid = (left + right) / 2;
    if(mid >= 0 && mid < v.size()) {
        if(x > v[mid]) {
            if(std::abs(v[mid] - x) < res.second) {
                res.second = std::abs(v[mid] - x);
                std::cout << " x: " << x << "  / v[mid]: " << v[mid] <<  "  / res 2: " << res.second << std::endl;
            }
            BinarySearch(x, v, mid + 1, right, res);
        } else if(x < v[mid]) {
            if(std::abs(v[mid] - x) < res.first) {
                res.first = std::abs(v[mid] - x);

                std::cout << " x: " << x << "  / v[mid]: " << v[mid] <<  "  / res 1: " << res.first << std::endl;
            }
            BinarySearch(x, v, left, mid - 1, res);
        } else { // x == v[mid]
            res.first = 0;
            return;
        }
    }

    return;
}

int main()
{
    std::vector<int> v1 = { 1, 3, 15, 11, 2 };
    std::vector<int> v2 = { 23, 127, 235, 19, 8 };

    std::sort(v1.begin(), v1.end());

    std::pair<int, int> res = {INT_MAX, INT_MAX};
    int minDiff = INT_MAX;
    for(int ii = 0; ii < v2.size(); ++ii) {
        BinarySearch(v2[ii], v1, 0, v1.size(), res);
        if(res.first < minDiff) minDiff = res.first;
        if(res.second < minDiff) minDiff = res.second;
    }

    std::cout << minDiff << std::endl;

    return 0;
}