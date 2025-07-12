#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0716NumberMax.cpp -o hola

int main()
{
    double n1 = 34;
    double n2 = 61;

    double max1 = static_cast<double>(std::abs(n1 + n2)) / 2;
    double max2 = static_cast<double>(std::abs(n1 - n2)) / 2;

    std::cout << "max1: " << max1 << "  / max2: " << max2 << std::endl;
    std::cout << max1 + max2 << std::endl;

    return 0;
}