//https://codeforces.com/contest/1875/problem/B
// Div. 2
// 1000 *1200

// Jellyfish and Game

// g++ -o b b.cpp

// game
// brute force
// greedy
// implementation

// If it's even, don't mind to do two operations.
//  or even to put it in a vector and sort it.

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, k;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> m >> k;
        ll maxA = 0;
        ll maxB = 0;
        ll minA = LLONG_MAX;
        ll minB = LLONG_MAX;
        ll sumA = 0;
        ll sumB = 0;

        for(int ii = 0; ii < n; ++ii) {
            std::cin >> a;
            sumA += a;
            if(a > maxA) {
                maxA = a;
            }
            if(a < minA) {
                minA = a;
            }
        }

        for(int ii = 0; ii < m; ++ii) {
            std::cin >> b;
            sumB += b;
            if(b > maxB) {
                maxB = b;
            }
            if(b < minB) {
                minB = b;
            }
        }


        ll max = maxA;
        if(maxB > maxA) {
            max = maxB;
        }
        ll min = minA;
        if(minB < minA) {
            min = minB;
        }

        if(k % 2 == 1) { // Odd.
            if(minA < maxB) {
                std::cout << sumA + maxB - minA << std::endl;
            } else {
                std::cout << sumA << std::endl;
            }
        } else { // Even.
            if(minA < maxB) {
                sumA = sumA + maxB - minA;
            }
            std::cout << sumA + min - max << std::endl;
        }

    }

}
