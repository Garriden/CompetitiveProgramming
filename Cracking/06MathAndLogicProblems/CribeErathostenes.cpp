#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 CribeErathostenes.cpp -o hola

std::vector<bool> Criba(int n)
{
    std::vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p*p <= n; ++p) {
        if(isPrime[p]) {
            for(int ii = p * p; ii <= n; ii += p) {
                isPrime[ii] = false;
            }
        }
    }

    return isPrime;
}

int main()
{
    std::vector<bool> b(100);
    b = Criba(100);

    for(int ii = 0; ii < 100; ++ii) {
        std::cout << ii << ": " << b[ii] << std::endl;
    }

    return 0;
}