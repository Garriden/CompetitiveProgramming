// https://codeforces.com/contest/2149/problem/B
// Div. 3
//
// 12 min

// Unconventional Pairs

// g++ -o b b.cpp

// greedy
// sortings

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
    ll max = -INT_MAX;
    ll min = INT_MAX;

    std::cin >> n;
    ll N = n;

    //std::vector<std::set<ll> > v(m);
    std::vector<ll> v(n, 0);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> v[ii];
    }

    std::sort(v.begin(), v.end());

    for(int ii = 0; ii < n; ii += 2) {
        ll resta = std::abs(v[ii] - v[ii+1]);
        max = std::max(max, resta);
    }

    //if(max == 3 && min == 1 && m == 2) {
    //    std::cout << "No" << std::endl;
    //    return;
    //}
    //if(min == 0) {
    //    std::cout << "nO" << std::endl;
    //    return;
    //}

    std::cout << max << std::endl;
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
