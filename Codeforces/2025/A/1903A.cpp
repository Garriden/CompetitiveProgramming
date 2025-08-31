//https://codeforces.com/contest/1903/problem/A
// Div. 2
// 500  *800

// Halloumi Boxes

// g++ -o a a.cpp

// sortings
// brute force
// greedy
 
// if k > 1, always can be sorted because 2 means swaping consecutive elements (bubble sort ?)
// if k == 1, check non-decreasing order.
 
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;
 
void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> n >> k;
 
    std::vector<ll> v(n);
    ll max = 0;
    ll maxPos = 0;
    ll anterior = 0;
    bool NO = false;
 
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> v[ii];
        if(v[ii] >= anterior) {
 
        } else {
            NO = true;
            //std::cout << "NO" << std::endl;
        }
        anterior = v[ii];
    }
 
    if(k < 2 && NO) {
        std::cout << "NO" << std::endl;
        return;
    }
/*
    NO = false;
    anterior = 0;
    for(int ii = 0; ii < n; ++ii) {
        if(v[ii] >= anterior) {
 
        } else {
            NO = true;
            //std::cout << "NO" << std::endl;
        }
        anterior = v[ii];
    }
*/
    //std::cout << "max: " << max << std::endl;
    std::cout << "YES" << std::endl;
}
 
int main() {
    int t;
    std::cin >> t;
 
    while(t --> 0) {
        solve();
    }
 
}