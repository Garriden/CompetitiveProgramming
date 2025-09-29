// https://codeforces.com/contest/1921/problem/C
// Div. 3
//  *900
// 41 min

// Sending Messages

// g++ -o c c.cpp

// greedy
// math

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p, f;
    std::string s;
    ll modulo = 998244353;

    std::cin >> n >> f >> a >> b;

    std::vector<ll> va(n, 0);
    std::vector<ll> accum(n, 0);
    //std::vector<ll> vb(n);
    //std::set<ll> set;
    ll max = -INT_MAX;
    ll sum = 0;
    
    //std::vector<ll> vFreq(200024, 0);
    //std::map<ll, ll> mapFreq; // key=number / value=freq

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    sum = std::min( (va[0] * a), b);
    for(int ii = 0; ii < n - 1; ++ii) {
        //accum[ii] = std::min( ((va[ii+1] - va[ii]) * a), b);
        sum += std::min( ((va[ii+1] - va[ii]) * a), b);
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
    //std::cout << sum << std::endl;
    //std::cout << "sum:" << sum << std::endl;

    if(sum < f) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
