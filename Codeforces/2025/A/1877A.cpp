//https://codeforces.com/contest/1877/problem/A
// Div. 2
// 500 *800

// Goals of Victory

// g++ -o a a.cpp

// math

// Just a sum.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, k;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        ll sum = 0;

        for(int ii = 0; ii < n - 1; ++ii) {
            std::cin >> a;
            sum += a;
        }

        //std::cout << "sum: " << sum << std::endl;
        std::cout << -1 * sum << std::endl;

    }

}
