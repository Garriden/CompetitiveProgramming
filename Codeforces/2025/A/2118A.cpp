//https://codeforces.com/contest/2118/problem/A
// Div. 2
// 500

// Equal Subsequences

// g++ -o a a.cpp

// constructive algorithms

// See that I just can fill with ones and then with zeros.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;

    std::vector<int> va(n, 0);

    int kOrig = k;
    for(int ii = 0; k > 0 && ii < n; ++ii) {
        if(k > 0) {
            va[ii] = 1;
        } else {
            va[ii] = 0;
        }
        --k;
    }

    for(int ii = 0; ii < n; ++ii) {
        std::cout << va[ii];
    } std::cout << std::endl;

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
