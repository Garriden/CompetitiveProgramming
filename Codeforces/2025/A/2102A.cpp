//https://codeforces.com/contest/2102/problem/A
// Div. 2
// 250

//g++ -o a a.cpp

// Math
// Contrustive Algorithms

// sum of p consecutive elements should be equal to q. -> a(i) = a(i+p)
// Find the math function.
// Catch the "NO" cases.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, m, p, q;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> m >> p >> q;

        if(((n/p * q) != m) && (n%p == 0)) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }

    }
    return 0;
}