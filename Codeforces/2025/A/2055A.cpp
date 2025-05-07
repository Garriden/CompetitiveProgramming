// Two Frogs
//https://codeforces.com/contest/2055/problem/A
// Div. 2
// 500

//g++ -o a a.cpp

// Games
// Constructive algorithms
// Greedy
// Math

// Playing Optimally, Alice goes closer to Bob in order to make Bob have no valid moves.
// The distance between Alice and Bob must be even. (Or odd in the sum inside a vector).

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA;
    ll a, b;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        std::cin >> a;
        std::cin >> b;

        if(((a+b) % 2) == 0) {
            std::cout << "YES" << std::endl;           
        } else {
            std::cout << "NO" << std::endl;
        }

    }
    return 0;
}