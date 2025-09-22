// https://codeforces.com/contest/2147/problem/D
// Global Round
// 2000
//

// Game on Array

// g++ -o d d.cpp

// WA
// Let's separate odd and even numbers. One can intuitively see that it is bad to choose x even,
//  since right after the other player can choose x−1 and get at least as many points as you did.
// This however is not true for odd numbers since after picking x=1, the opposite player cannot pick x=0


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
    ll max = 0;
    std::cin >> n;
    std::vector<ll> vFreq(200024, 0);
    std::map<ll, ll> mapFreq; // key=number / value=freq

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> k;
        vFreq[k]++;
        max = std::max(max, k);
    }
    ++max;

    for(int ii = 0; ii < max; ++ii) {
        std::cout << vFreq[ii] << " ";
    } std::cout << std::endl;

    ll ana = 0;
    ll bob = 0;
    bool anaTurn = true;
    for(int ii = max; ii > 0; --ii) {
        ll frequencia = vFreq[ii];
        if(frequencia != 0) {
            if(anaTurn) {
                ana += frequencia;
            } else {
                bob += frequencia;
            }
            anaTurn = !anaTurn;

            vFreq[ii] = 0;
            vFreq[ii - 1] += frequencia;
        }
        //std::cout << "  ana: " << ana << "   bob: " << bob << std::endl;
    }
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
    std::cout << ana << " " << bob << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
