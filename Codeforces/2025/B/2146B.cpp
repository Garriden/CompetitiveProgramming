// https://codeforces.com/contest/2146/problem/B#
// Div. 2
// 1000

// Merging the Sets

// g++ -o b b.cpp

// flows
// greedy
// implementation

// WA f

/*
2 1
1 1
1 1
Should return YES
*/

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

    std::cin >> n >> m;
    ll N = n;

    std::vector<std::set<ll> > v(m);
    std::vector<bool> vAllElements(m, false);

    ll index = 0;
    while(n --> 0) {
        std::cin >> l;
        for(ll ii = 0; ii < l; ++ii) {
            std::cin >> x;
            v[x-1].insert(index);
            vAllElements[x-1] = true;
        }
        ++index;
    }

    for(int ii = 0; ii < vAllElements.size(); ++ii) {
        if(!vAllElements[ii]) {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    ll max2Ocur = 0;
    for(ll ii = 0; ii < v.size(); ++ii) {
        //std::cout << "  " << ii << ": ";
        if((ll)v[ii].size() == 2) {
            ++max2Ocur;
        }

        max = std::max(max, (ll)v[ii].size());
        min = std::min(min, (ll)v[ii].size());

        //for(auto elem : v[ii]) {
        //    std::cout << elem << " ";
        //} std::cout << std::endl;
    }

    //std::cout << "max2Ocur: " << max2Ocur << std::endl;
    if(max == 2 && m <= 2 && N <= 2) {
        std::cout << "nO" << std::endl;
        return;
    }

    if(max == 2) {
        //if(max2Ocur < 2 /*&& N == m*/) {
        if(max2Ocur < 2 /*&& N == m*/) {
            std::cout << "no" << std::endl;
            return;
        }
    }

    if(max == 1 && ) {
        std::cout << "No" << std::endl;
        return;
    }

    //if(max == 3 && min == 1 && m == 2) {
    //    std::cout << "No" << std::endl;
    //    return;
    //}
    //if(min == 0) {
    //    std::cout << "nO" << std::endl;
    //    return;
    //}

    std::cout << "YES" << std::endl;
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
