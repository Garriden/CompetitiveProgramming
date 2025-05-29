//https://codeforces.com/contest/1884/problem/A
// Div. 2
// 500

// Simple design

// g++ -o b b.cpp

// brute force
// greedy
// math

// Count digits + divisible.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

ll sumDigits(ll x) {
    ll sum = 0;

    while(x > 9) {
        sum += (x % 10);
        x /= 10;
    }

    return sum + x;
}

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;

    //std::cout << sumDigits(n) << std::endl;

    for(ll ii = n; ii <= 10000000000; ++ii) {
        if((sumDigits(ii) % k) == 0) {
            std::cout << ii << std::endl;
            return;
        }
    }
    /*
    if(zeros == ones) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    */
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
