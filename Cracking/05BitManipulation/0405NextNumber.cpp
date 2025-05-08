#include <iostream>
#include <cstdint>
#include <math.h>
#include <string.h>
#include <iomanip> //binary, std::setbase(2)
#include <format>

// g++ .\0405NextNumber.cpp -o hola


uint32_t GetHigher(uint32_t x)
{
    uint32_t aux = x;
    uint32_t rightMostZero = 0;
    uint32_t oneCounts = 0;

    // Find the position of the right-most zero which has ones to the right of it.
    while(((aux & 1) == 0) && (aux != 0)) {
        ++rightMostZero;
        aux = aux >> 1;
    }
    //std::cout << rightMostZero <<std::endl;

    while(((aux & 1) == 1) && (aux != 0)) {
        ++oneCounts;
        aux = aux >> 1;
    }
    //std::cout << rightMostZero + oneCounts <<std::endl;
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // Flip the right-most zero which has ones to the right of it.
    // 11 0110 0111 1100
    // 11 0110 1111 1100
    aux = aux | 1;
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // Clear the right zeros.
    // 11 0110 1111 1100
    // 11 0110 1000 0000
    aux = aux << (rightMostZero + 1);
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // Full thre remaining ones.
    // 11 0110 1000 0000
    // 11 0110 1000 1111
    //aux |= ((1 << (oneCounts - 1)) - 1);
    for(int ii = 0; ii < oneCounts - 1; ++ii) {
        aux = (aux << 1) | 1;
    }
    //std::cout << std::format("{:b}", aux) <<std::endl;
    
    return aux;
}

uint32_t GetLower(uint32_t x)
{
    uint32_t aux = x;
    uint32_t rightMostZero = 0;
    uint32_t oneCounts = 0;

    // Clear bits
    // Find the position of the right-most zero which has ones to the right of it.
    while(((aux & 1) == 1) && (aux != 0)) {
        ++oneCounts;
        aux = aux >> 1;
    }
    //std::cout << oneCounts <<std::endl;

    while(((aux & 1) == 0) && (aux != 0)) {
        ++rightMostZero;
        aux = aux >> 1;
    }
    //std::cout << rightMostZero <<std::endl;
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // 0010 0111 1000 0000
    // 0010 0111 0000 0000
    //uint32_t mask = ~static_cast<uint32_t>(0);
    uint32_t mask = 0xFFFFFFFE;
    aux = aux & mask;
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // Add ones
    // 0010 0111 0000 0000
    // 0010 0111 0111 0000
    for(int ii = 0; ii < oneCounts + 1; ++ii) {
        aux = (aux << 1) | 1;
    }
    //std::cout << std::format("{:b}", aux) <<std::endl;

    // Add right zeros.
    // 0010 0111 0111 0000
    // 0010 0111 0111 0000
    aux = aux << rightMostZero - 1;
    //std::cout << std::format("{:b}", aux) <<std::endl;

    return aux;
}

int main()
{
    uint32_t n = 13948; //11011001111100
    uint32_t higher = 13967; // 11011010001111
    uint32_t n2 = 10115; //0010011110000011
    uint32_t lower = 10096; //10011101110000

    std::cout << (GetHigher(n) == higher) << std::endl;
    std::cout << (GetLower(n2) == lower) << std::endl;

    return 0;
}