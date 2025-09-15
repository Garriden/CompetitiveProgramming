// https://codeforces.com/contest/1916/problem/A
// Div
// 250  *800

// 2023

// g++ -o a a.cpp

// math
// number theory
// implementation

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 1;
    

    std::cin >> n >> k;

    std::vector<ll> vb(n);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
        max *= vb[ii];
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << "(2023.0 / max): " << (2023.0 / max) << std::endl;

    //std::accumulate(vb.begin(), vb.end(), max);

    if((2023 % max) == 0) {
        std::cout << "YES" << std::endl;
        std::cout << (2023.0 / max) << " ";
        while(k --> 1) {
            std::cout << 1 << " ";
        }

        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }


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
