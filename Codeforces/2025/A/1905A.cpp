//https://codeforces.com/contest/1905/problem/A
// Div. 2
// 500  *800

// Constructive Problems

// g++ -o a a.cpp

// math

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    ll max = 0;
    ll maxPos = 0;
    ll anterior = 0;
    bool NO = false;

    std::cin >> n >> m;
    max = std::max(n, m);

    //std::cout << "max: " << max << std::endl;
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
