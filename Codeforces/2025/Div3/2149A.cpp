// https://codeforces.com/contest/2149/problem/A
// Div. 3
//
// 5 min

// Be positive

// g++ -o a a.cpp

// math


#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, m, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;
    ll max = 0;
    ll min = INT_MAX;

    std::cin >> n;
    ll N = n;
    ll sum = 0;
    ll negs = 0;

    ll index = 0;
    while(n --> 0) {
        std::cin >> l;

        if(l == -1) {
            ++negs;
        } else if(l == 0) {
            ++sum;
        }
    }

    if(negs % 2 == 0) {
        // ok.
    } else {
        ++++sum;
    }

    //if(max == 3 && min == 1 && m == 2) {
    //    std::cout << "No" << std::endl;
    //    return;
    //}
    //if(min == 0) {
    //    std::cout << "nO" << std::endl;
    //    return;
    //}

    std::cout << sum<< std::endl;
    //std::cout << "max: " << max << std::endl;
    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
