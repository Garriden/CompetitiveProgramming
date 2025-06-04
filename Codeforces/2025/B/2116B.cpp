//https://codeforces.com/contest/2116/problem/B
// Div. 2
// 750 ?

// Gellyfish and Baby's Breath

// g++ -o b b.cpp

// greedy
// math
// sortings ?
// auxiliar vector

// Having an auxiliar vector of maxPositions.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

ll power2(ll exp) {
    ll res = 1;
    ll base = 2;
    base %= MOD;
    while(exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> n;

    std::vector<ll> p(n);
    std::vector<ll> q(n);
    std::vector<ll> pMaxsPos(n, 0);
    std::vector<ll> qMaxsPos(n, 0);
    ll max = 0;
    ll maxPos = 0;

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> p[ii];
        if(p[ii] > max) {
            max = p[ii];
            maxPos = ii;
        }
        pMaxsPos[ii] = maxPos;
    }

    max = 0;
    maxPos = 0;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> q[ii];
        if(q[ii] > max) {
            max = q[ii];
            maxPos = ii;
        }
        qMaxsPos[ii] = maxPos;
    }

    for(int ii = 0; ii < n; ++ii) {
        max = 0;
        ll max1 = 0;
        ll max2 = 0;
        ll min = -1;
        ll min1 = -1;
        ll min2 = -1;

        // Watch for his pair.
        max1 = p[pMaxsPos[ii]];
        min1 = q[(ii) - pMaxsPos[ii]];
        // Watch for his pair.
        max2 = q[qMaxsPos[ii]];
        min2 = p[(ii) - qMaxsPos[ii]];

        //std::cout << "max1: " << max1 << "  / min1: " << min1 << "   // max2: " << max2 << "  / min2: " << min2 << std::endl;

        // Select the maximum pair.
        if(max2 > max1) {
            max = max2;
            min = min2;
        } else if(max1 > max2) {
            max = max1;
            min = min1;
        } else { // equal
            max = max1;
            min = min1;
            if(min2 > min1) {
                min = min2;
            }
        }

        //std::cout << "max: " << max << std::endl;
        std::cout << (power2(max) + power2(min)) % MOD << " ";
    }
    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
