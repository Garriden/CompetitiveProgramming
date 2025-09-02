// 2 problems solved, 1150 rating
//https://codeforces.com/contest/1902/problem/A
// Div. 2
// *800

// Binary Imbalance

// g++ -o a a.cpp

// constructive algorithms

// Just check is there is some zero.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::cin >> n;

    std::string s = "";
    ll max = 0;
    ll maxPos = 0;
    ll anterior = 0;
    bool zero = false;

    std::cin >> s;
    if(s.find('0') != std::string::npos) { // zero found.
        zero = true;
    }


    if(zero) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << "YES" << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
