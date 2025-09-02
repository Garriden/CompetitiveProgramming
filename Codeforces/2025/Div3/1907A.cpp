// https://codeforces.com/contest/1907/problem/A
// Div. 3
// *800

// Rook

// g++ -o a a.cpp

// implementation

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    ll P, l, t;
    std::string s;
    std::cin >> s;

    char col = s[0];
    char row = s[1];

    for(int ii = 0; ii < 8; ++ii) {
        std::string aux = col + std::to_string(ii+1);
        if(aux != s) {
            std::cout << aux << std::endl;
        }
    }

    for(int ii = 0; ii < 8; ++ii) {
        char charAux = 'a' + ii;
        std::string s24 = std::string(1, charAux) + row;
        if(s24 != s) {
            std::cout << s24 << std::endl;
        }
    }

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
