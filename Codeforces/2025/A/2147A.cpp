// https://codeforces.com/contest/2147/problem/A
// Global Round
// 500
// 25m

// Shortest Increasing Path

// g++ -o a a.cpp

// constructive algorithms

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
    ll min = 0;
    ll max = INT_MAX;
        std::cin >> x >> y;

        if(y > x) {
            std::cout << 2 << std::endl;
        } else if(x == y) {
            std::cout << -1 << std::endl;
        } else {
            if(y == 1) {
                std::cout << -1 << std::endl;
            } else if((x-y) <= 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << 3 << std::endl;
            }
        }


        //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "max: " << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
