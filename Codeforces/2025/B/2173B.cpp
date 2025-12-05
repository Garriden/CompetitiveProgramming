// https://codeforces.com/contest/2173/problem/B
// Codeforces Round 1068 (Div. 2)
//  1000

// Niko's Tactical Cards

// g++ -o b b.cpp

// dp
// greedy

// Game.
// Discover pattern.
// The blue operation, negates the current score and adds. 
// This creates a pattern where depends on the parity of blue choices.

// RR -> -a1 - a2
// RB ->  a1 + b2
// BR ->  b1 - a2
// BB ->  b2 - b1

// dp[0]: maximum score with even number of blues in positions processed so far
// dp[1]: maximum score with odd number of blues in positions processed so far

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;

    //std::cin >> n;


    //std::set<ll> set;
    ll min = 0;
    ll max = INT_MAX;
    std::cin >> n;
    std::vector<ll> va(n);
    std::vector<ll> vb(n);

    int cont = -1;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
    }

    ll res = 0;
    ll dp0 = -va[n-1];
    ll dp1 = vb[n-1];

    for(int ii = n - 2; ii >= 0; --ii) {

        ll aux1 = std::max(dp0 - va[ii], dp1 - vb[ii]);
        ll aux2 = std::max(dp1 + va[ii], dp0 + vb[ii]);

        dp0 = aux1;
        dp1 = aux2;

    }

    res = std::max(dp0, dp1);

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "res: " << res << std::endl;
    std::cout << res << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
