#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0916Operations.cpp -o hola

int Minus(int x, int y)
{
    return x + (y * -1);
}

int Times(int x, int y)
{
    int ret = 0;

    while(y --> 0) {
        ret += x;
    }

    return ret;
}

int Div(int x, int y)
{
    int count = 0;

    while(y --> 0) {
        ++count;
    }

    return count;
}

int main()
{
    std::cout << "4 - 2: " << Minus(4, 2) << std::endl;
    std::cout << "4 * 2: " << Times(4, 2) << std::endl;
    std::cout << "4 / 2: " << Div(4, 2) << std::endl;

    return 0;
}