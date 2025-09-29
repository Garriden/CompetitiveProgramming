// https://codeforces.com/contest/1921/problem/B
// Div. 3
//  *800
// 22 min

// Arranging Cats

// g++ -o b b.cpp

// greedy
// implementation

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

    //std::vector<ll> va(n);
    //std::vector<ll> vb(n);
    //std::set<ll> set;
    ll max = -INT_MAX;
    
    //std::vector<ll> vFreq(200024, 0);
    //std::map<ll, ll> mapFreq; // key=number / value=freq
    ll mustBeOnes = 0;
    ll mustBeZeros = 0;
    std::string sa;
    std::cin >> sa;
    std::string sb;
    std::cin >> sb;

    for(int ii = 0; ii < n; ++ii) {
        if(sa[ii] == '0' && sb[ii] == '1') {
            ++mustBeOnes;
        }

        if(sa[ii] == '1' && sb[ii] == '0') {
            ++mustBeZeros;
        }

    }

    max = std::max(mustBeOnes, mustBeZeros);

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
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
