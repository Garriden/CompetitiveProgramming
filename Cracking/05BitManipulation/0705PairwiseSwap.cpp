#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>

// g++ .\0705PairwiseSwap.cpp -o hola

int main()
{
    uint32_t n = 9;         // 1001
    uint32_t solution = 6;  // 0110
    uint32_t mask = 3;      // 0011

    // My solution.
    for(int ii = 0; ii < 2; ++ii) {
        //std::cout << std::format("{:b}", n) <<std::endl;
        n ^= mask;
        //std::cout << std::format("{:b}", n) <<std::endl;
        mask <<= 2;
    }

    // Right solution.
    // Shift odd bits one to the right. Shift even bits one to the other direction, from the original x.
    uint32_t a = ((n & 0xAAAAAAAA >> 1) | (n & 0x55555555 << 1));

    std::cout << (a == solution) << std::endl;
    std::cout << (n == solution) << std::endl;

    return 0;
}