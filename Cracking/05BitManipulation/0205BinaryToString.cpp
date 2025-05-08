#include <iostream>
#include <cstdint>
#include <math.h>
#include <string.h>

// g++ .\0205BinaryToString.cpp -o hola

int main()
{
    double n = 0.72;
    double half = 0.5;
    std::string s = "0.";

    for(int ii = 0; ii < 32 && n != 0.0; ++ii) {
        if(n - half > 0) {
            s += '1';
            n -= half;
        } else {
            s +='0';
        }
        half /= 2;
    }
    std::cout << s << std::endl;

    return 0;
}