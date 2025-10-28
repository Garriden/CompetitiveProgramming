// https://codeforces.com/contest/2145/problem/A
// Educational Codeforces Round.
//   *800
// 3 min.

// Candies for Nephews

// g++ -o a a.cpp

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
    ll modulo = 998244353;

    //std::cin >> n;

    //std::vector<ll> va(n);
    //std::vector<ll> vb(n);
    //std::set<ll> set;
    ll min = 0;
    ll max = INT_MAX;
    std::cin >> n;

    if(n % 3 == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 3 - (n%3) << std::endl;
    }
    
    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
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
