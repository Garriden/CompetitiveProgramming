//https://codeforces.com/contest/1878/problem/A
// Div. 3
// 800 ?

// How Much Does Daytona Cost?

// g++ -o a a.cpp

// greedy
// math

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a, k;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        bool exists = false;

        std::cin >> n;
        std::cin >> k;

        for(ll ii = 0; ii < n; ++ii) {
            std::cin >> a;
            if(a == k) {
                exists = true;
            }
        }

        if(exists) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

}
