#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>
#include <random>
#include <limits> // Required for numeric_limits

// g++ -std=c++20 0906100Lockers.cpp -o hola

// A locker would be left open when his factors will be odd.
//  Ex: 15: 1,3,5,15 would be closed.
// Just would be odd when a factor doesn't have a complement.
//  Ex: 36 -> (1,36) (2,18) (3,12) (4,9) (6,6): this [6*6] is the key.
// So a locker would be left open when a number is a perfect square: 1*1, 2*2, 3*3...

// Now a simulation:
int main()
{
    int n = 100;

    std::vector<bool> open(n+1, false);

    for(int ii = 1; ii <= n; ++ii) {
        for(int jj = ii; jj <= n; jj += ii) {
            open[jj] = !open[jj];
        }
    }

    int cont = 0;
    for(int ii = 1; ii <= n; ++ii) {
        if(open[ii]) {
            ++cont;
        }
        std::cout << open[ii];
    }
    std::cout << std::endl;

    std::cout << "Lockers open: " << cont << std::endl;

    return 0;
}