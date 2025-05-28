//https://codeforces.com/contest/2114/problem/A
// Div. 3
// 2

// Not Quite a Palindromic String

// g++ -o b b.cpp

// math
// greedy

// Match parity + control k.
// solve

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;
    std::cin >> s;

    int zeros = 0;
    int ones = 0;
    for(int ii = 0; ii < n; ++ii) {
        if(s[ii] == '0') {
            ++zeros;
        } else if(s[ii] == '1') {
            ++ones;
        }

    }

    int res = std::abs(zeros - ones);
    int kaux = k;

    while(kaux--) {
        if(zeros < 2 && ones < 2) {
            std::cout << "NO" << std::endl;
            return;
        }

        if(zeros > ones) {
            zeros -= 2;
        } else {
            ones -= 2;
        }
        
    }

    //std::cout << "k: " << k << std::endl;
    //std::cout << "res / 2: " << res / 2 << std::endl;

    if(zeros == ones) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    //std::cout << "sum: " << sum << std::endl;
    //std::cout << sum << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
