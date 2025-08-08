#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 1116DivingBoard.cpp -o hola

// 4+4+4=12
// 4+4+6=14
// 4+6+6=16
// 6+6+6=18 

int main()
{
    int k = 3;
    int shorter = 4;
    int larger = 6;

    int diff = larger - shorter;
    int firstValue = shorter * k;
    for(int ii = 0; ii < k + 1; ++ii) {
        std::cout << "Size: " << firstValue + ii * diff << std::endl;
    }

    return 0;
}