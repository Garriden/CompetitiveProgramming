//https://codeforces.com/contest/1899/problem/A
// Div. 3
// 1  *800

// Game with Integers

// g++ -o a a.cpp

// games
// math
// number theory

// Divisible by 3

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    int as = 0;
    int bs = 0;

    if(((n - 1) % 3 == 0) || ((n + 1) % 3 == 0)) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
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
