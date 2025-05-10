#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ .\0805DrawLine.cpp -o hola

int DrawLine(const std::vector<int> &screen, int width, int x1, int x2, int y)
{
    int line = y * width;

    for(int ii = 0; ii < screen.size(); ++ii) {
        if(ii % width == 0) {
            std::cout << std::endl;
        }
        if((ii >= line + x1) && (ii <= line + x2)) {
            std::cout << "X";
        } else {
            std::cout << "0";
        }

    }

    return 0;
}

int main()
{
    uint32_t n = 9;         // 1001
    uint32_t solution = 6;  // 0110
    uint32_t mask = 3;      // 0011

    std::vector<int> screen(64);

    DrawLine(screen, 16, 2, 14, 1);

    return 0;
}