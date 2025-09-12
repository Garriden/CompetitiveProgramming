// https://codeforces.com/contest/1917/problem/B
// Div. 2
// 1000  *1100

// Erase First or Second Letter

// g++ -o b b.cpp

// brute force
// combinatorics
// data structures
// dp
// strings

// Can be done in O(n).

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void recu(std::unordered_set<std::string> &dp, const std::string &s)
{
    if(s.size() == 0) { // base case.
        return;
    }

    if(dp.count(s) == 0) {
        dp.insert(s);

        recu(dp, s.substr(1));

        if(s.size() > 1) {
            recu(dp, s.substr(0, 1) + s.substr(2));
        }
    }
}

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 0;

    std::cin >> n;
    std::cin >> s;

    std::unordered_set<std::string> dp;

    std::string s1 = s;
    std::string s2 = s;

    recu(dp, s);

    //std::cout << "max: " << max << std::endl;
    std::cout << dp.size() << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
