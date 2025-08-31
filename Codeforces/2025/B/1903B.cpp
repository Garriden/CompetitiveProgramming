//https://codeforces.com/contest/1903/problem/B
// Div. 2
// 1000  *1200

// StORage room

// g++ -o b b.cpp

// bitmasks
// brute force
// constructive algorithms
// greedy

// bitwise & ?

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> n;

    std::vector<std::vector<ll>> M(n, std::vector<ll>(n));
    std::vector<ll> va(n, 0);
    ll max = 0;
    ll maxPos = 0;
    ll anterior = 0;
    bool NO = false;

    for(int ii = 0; ii < n; ++ii) {
        for(int jj = 0; jj < n; ++jj) {
            std::cin >> M[ii][jj];
        }
    }

    for(int ii = 0; ii < n; ++ii) {
        ll bitmask = (1LL << 30) - 1;
        for(int jj = 0; jj < n; ++jj) {
            if(ii != jj) {
                bitmask &= M[ii][jj];
            }
        }
        va[ii] = bitmask;
    }

    for(int ii = 0; ii < n && !NO; ++ii) {
        for(int jj = 0; jj < n; ++jj) {
            if(ii != jj) {
                if((va[ii] | va[jj]) != M[ii][jj]) {
                    NO = true;
                    break;
                }
            }
        }
    }

    if(NO) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        for(int ii = 0; ii < n; ++ii) {
            std::cout << va[ii] << " ";
        } std::cout << std::endl;
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
