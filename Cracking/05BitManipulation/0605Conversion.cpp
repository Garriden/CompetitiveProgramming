#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>

// g++ .\0605Conversion.cpp -o hola

std::string intToBinaryBitset(int n) {
    std::bitset<sizeof(int) * 8> b(n); // sizeof(int) (4 bytes) * 8 bits (en un byte) = 32.
    return b.to_string();
}

int main()
{
    uint32_t n1 = 29; //11101
    uint32_t n2 = 15; //01111
    //std::string s1 = intToBinaryBitset(n1);
    //std::string s2 = intToBinaryBitset(n2);
    int ret = n1 ^ n2;
    int cont = 0;
    while(ret != 0) {
        cont += (ret & 1); // if the last bit is one.
        ret >>= 1;
    }

    //for(int ii = 0; ii < s1.size(); ++ii) {
    //    cont += s1[ii] ^ s2[ii];
    //}

    std::cout << cont << std::endl;

    return 0;
}