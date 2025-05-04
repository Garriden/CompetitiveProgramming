#include <iostream>
#include <cstdint>
#include <bitset>

// g++ .\0105Insertion.cpp -o hola

uint32_t setBit(uint32_t value, int bitPosition) {
    return value | (1 << bitPosition);
}

uint32_t clearBit(uint32_t value, int bitPosition) {
    return value & ~(1 << bitPosition);
}

int main()
{
    uint32_t n,m,i,j = 0;

    n = 1000000000; // 0b1000000000;
    m = 10011; // 0b10011;
    i = 2;
    j = 6;

    //std::cout << std::binary  << n|(m<<i) << std::endl;

    while(i-->0) {
        m *= 10;
    }

    uint32_t ret = n + m;

    std::cout << ret << std::endl;

    return 0;
}