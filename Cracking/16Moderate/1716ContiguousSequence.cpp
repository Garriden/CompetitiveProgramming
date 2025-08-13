#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <limits.h>

// g++ 1716ContiguousSequence.cpp -o hola

// Maximum subarray problem.

int main()
{
    std::vector<int> v{2, -8, 3, -2, 4, -10};

    int ant = 0;
    int sum = 0;
    int max = INT_MIN;
/*
    for(int ii = 0; ii < v.size(); ++ii) {
        ant = sum;
        sum += v[ii];

        if(sum > ant) {
            if(sum > max) {
                max = sum;
            }
        } else {
            //sum = 0;
        }

        if(v[ii] > sum) {
            sum = v[ii];
        }
    }
*/
    for(int ii = 0; ii < v.size(); ++ii) {
        sum += v[ii];

        if(sum > max) {
            max = sum;
        } else if(sum < 0) {
            sum = 0;
        }
    }

    std::cout << max << std::endl;

    return 0;
}