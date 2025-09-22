// https://codeforces.com/contest/2147/problem/B
// Global Round
// 1000
//

// Multiple Construction

// g++ -o b b.cpp

// constructive algorithms

// langford pairing problem ?

// [ n, n-1, n-2, ..., 3, 2, 1, n, 1, 2, 3, ..., n-2, n-1 ]
// It's easy to see that both occurrences of n are at a distance of 2n.
// The other ones are just at distance of 2n.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;

    std::cin >> n;
    ll N = n;

    if(n == 1) {
        std::cout << 1 << " " << 1 << std::endl;
        return;
    }
    //std::vector<ll> va(2*n);

    for(ll ii = n; ii >= 1; --ii) {
        std::cout << ii << " ";
    }

    std::cout << n << " ";

    for(ll ii = 1; ii < n; ++ii) {
        std::cout << ii << " ";
    }

    std::cout << std::endl;

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << ii << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "max: " << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
