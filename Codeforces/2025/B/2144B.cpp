// https://codeforces.com/contest/2144/problem/B
// Edu Div. 2
// 

// Maximum Cost Permutation

// g++ -o b b.cpp

// constructive algorithms
// greedy

// Queue

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 0;

    std::cin >> n;

    std::vector<ll> va(n);
    std::set<ll> exist;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        exist.insert(va[ii]);
    }

    std::queue<ll> rellenaleElPavo;
    for(int ii = n; ii >= 0; --ii) {
        if(exist.count(ii) == 0) {
            rellenaleElPavo.push(ii);
        }
    }

    l = 0;
    r = n - 1;
    bool firstOrdered = true;
    for(int ii = 0; ii < n; ++ii) {
        if(va[ii] == 0) {
            va[ii] = rellenaleElPavo.front();
            rellenaleElPavo.pop();
        }

        if(firstOrdered && va[ii] != (ii+1)) {
            firstOrdered = false;
            l = ii;
        }
    }

    for(int ii = n - 1; ii > 0; --ii) {
        if(va[ii] != (ii+1)) {
            r = ii;
            break;
        }
    }

    //for(int ii = 0; ii < n; ++ii) {
    //    std:: cout << va[ii] << " ";
    //} std::cout << std::endl;
    //std::cout << " l: " << l <<  "  / r: " << r << std::endl;

    //std::accumulate(vb.begin(), vb.end(), max);

    //std::cout << "max: " << max << std::endl;
    if(firstOrdered) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 + r - l << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
