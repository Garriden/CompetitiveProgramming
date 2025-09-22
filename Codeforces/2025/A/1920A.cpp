// https://codeforces.com/contest/1920/problem/A
// Div. 2
// 500
// 25m

// Satisfying Constraints

// g++ -o a a.cpp

// g

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

    std::cin >> n;

    std::vector<ll> va(n);
    std::vector<ll> vb(n);
    std::set<ll> set;
    ll min = 0;
    ll max = INT_MAX;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> a >> b;

        if(a == 2) {
            max = std::min(max, b);
        } else if(a == 1) {
            min = std::max(min, b);
        } else {
            set.insert(b);
        }

    }

    ll restar = 0;
    for(auto elem : set) { // Left.
        if(elem >= min && elem <= max) {
            ++restar;
        }
    }// std::cout << std::endl;

        //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "resss: " << 1 + max - min - restar << std::endl;
    if(min <= max) {
        std::cout << 1 + max - min - restar << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
