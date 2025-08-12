#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 1616SubSort.cpp -o hola

// 1st approach:
//  For each number, search if there is another minor on the restant vector.
//  O(n^2)

// 2nd approach:
//  Put all this vector into a set.
//  Checking for a min is just O(log n) every time.
//  O(n * log(n) ) 

int main()
{
    std::vector<int> v{1,2,4,10,11,7,12,6,7,16,18,19};

    std::set<int> set;

    // 4 and 16
    int left = 0;
    int right = v.size() - 1;

    for(int ii = 0; ii < v.size(); ++ii) {
        set.insert(v[ii]);
    }

    for(auto it : set) {
        std::cout << it << " ";
    } std::cout << std::endl;

    int ii = 0;
    for(auto elem : set) { // Left.
        if(v[ii++] == elem) { // min
            //set.erase(v[ii]);
            left = v[ii - 1];
        } else {
            break;
        }
        
    }

    ii = v.size() - 1;
    // Use a reverse iterator to start from the largest element. ReverseBegin
    for(auto it = set.rbegin(); it != set.rend(); ++it) {
        //std::cout << "v[ii]: " << v[ii] << "  / *set.end(): " << *it << std::endl;
        if(v[ii--] == *it) { // max
            //set.erase(v[ii]);
            right = v[ii + 1];
        } else {
            break;
        }

    }

    std::cout << " Last ordered left: " << left << "  / last ordered right: " << right << std::endl;

    return 0;
}