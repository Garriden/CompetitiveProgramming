// https://codeforces.com/contest/1917/problem/A
// Div. 2
// 500  *800

// Least Product

// g++ -o a a.cpp

// math
// constructive algorithms

// Watch for test case 0.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 0;

    std::cin >> n;
    std::vector<ll> v(n);
    ll negs = 0;
    ll negPos = 0;
    bool zero = false;

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> v[ii];

        if(v[ii] < 0) {
            ++negs;
            negPos = ii;
        }

        if(v[ii] == 0) {
            zero = true;
        }
    }

    if(zero) {
        std::cout << 0 << std::endl;
    } else if(negs == 0) {
        std::cout << 1 << std::endl << 1 << " " << 0 << std::endl;
    } else if(negs % 2 != 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl << negPos << " " << 0 << std::endl;
    }

    //for(int ii = n; ii > 0; --ii) {
    //    std::cout << ii << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << std::endl;
    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
