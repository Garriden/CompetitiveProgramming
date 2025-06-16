//https://codeforces.com/contest/1894/problem/A
// Div. 2
// 500

// Secret Sport

// g++ -o a a.cpp

// implementation
// strings
// games

// Just check the last value.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;
    std::cin >> s1;

    int as = 0;
    int bs = 0;

    if(s1[n-1] == 'A') {
        std::cout << "A" << std::endl;
    } else {
        std::cout << "B" << std::endl;
    }

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
