// https://codeforces.com/contest/1921/problem/A
// Div. 3
//  *800
// 5 min

// Square

// g++ -o a a.cpp

// greedy
// math

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

    //std::vector<ll> va(n);
    //std::vector<ll> vb(n);
    //std::set<ll> set;
    ll minX = 1000;
    ll maxX = -1000;
    ll minY = 1000;
    ll maxY = -1000;
    
    //std::vector<ll> vFreq(200024, 0);
    //std::map<ll, ll> mapFreq; // key=number / value=freq

    for(int ii = 0; ii < 4; ++ii) {
        std::cin >> x >> y;
        minX = std::min(minX, x);
        maxX = std::max(maxX, x);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }

    //for(int ii = 0; ii < max; ++ii) {
    //    std::cout << vFreq[ii] << " ";
    //} std::cout << std::endl;

/*
    if(anaTurn) {
        ana += vFreq[0];
    } else {
        bob += vFreq[0];
    }
*/
    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    std::cout << (maxX - minX) * (maxY - minY) << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
