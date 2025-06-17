// https://codeforces.com/contest/1898/problem/A
// Div. 2
// 500  *800

// Milica and String

// g++ -o a a.cpp

// brute force
// implementation
// strings

// Just check characters and iterate.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n >> k;
    std::cin >> s1;

    ll acont = 0;
    ll bcont = 0;

    for(int ii = 0; ii < n; ++ii) {
        if(s1[ii] == 'A') {
            ++acont;
        } else {
            ++bcont;
        }

    }

    int diff = std::abs(k - bcont);
    //std::cout << diff << std::endl;
    if(diff == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    char c = 'B';
    char otherC = 'A';
    if(k > bcont) {
        c = 'A';
        otherC = 'B';
    }

    std::cout << 1 << std::endl;
    //std::cout << "c: " << c << std::endl;
    for(int ii = 0; ii < n; ++ii) {
        if(s1[ii] == c) {
            --diff;
        }

        if(diff == 0) {
            std::cout << ii + 1 << " " << otherC << std::endl;
            return;
        }
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
