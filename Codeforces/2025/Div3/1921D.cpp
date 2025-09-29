// https://codeforces.com/contest/1921/problem/D
// Div. 3
//  *1100
// -

// Very Different Array

// g++ -o d d.cpp

// greedy
// data structures
// sortings
// two pointers

// Two two pointers.
// Sempre he de comprovar si puc ordenar tots els vectors.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, m, x, y, k, l, r;
    ll a, b, p, f;
    std::string s;
    ll modulo = 998244353;

    std::cin >> n >> m;

    std::vector<ll> va(n, 0);
    std::vector<ll> vb(m, 0);
    std::vector<ll> vc(n, 0);
    ll max = -INT_MAX;
    ll sum = 0;
    
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }
    for(int ii = 0; ii < m; ++ii) {
        std::cin >> vb[ii];
    }

    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());

    ll leftA = 0;
    ll rightA = n - 1;
    ll leftB = 0;
    ll rightB = m - 1;
    for(int ii = 0; ii < n; ++ii) {
        ll sumMax = std::abs(va[leftA]  - vb[rightB]);
        ll sumMin = std::abs(va[rightA] - vb[leftB]);
        //std::cout << "element: " << element << "  / vb[left]: " << vb[left] << "  /  vb[right]: " <<  vb[right] << std::endl;
        if(sumMax >= sumMin) {
            sum += sumMax;
            ++leftA;
            --rightB;
        } else if(sumMax < sumMin) {
            sum += sumMin;
            --rightA;
            ++leftB;
        }

        //std::cout << "sum: " << sum << std::endl;
    }

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    std::cout << sum << std::endl;
    //std::cout << "sum: " << sum << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
