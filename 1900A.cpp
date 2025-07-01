//https://codeforces.com/contest/1900/problem/A
// Div. 2
// 500  *800

// Cover in Water

// g++ -o a a.cpp

// greedy
// constructive algorithms

// Wat.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;
    std::cin >> s;

    std::vector<int> v(4);
    int acum = 0;
    for(int ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == '.') {
           ++acum;
        } else {
            if(acum > 2) acum = 3;
            v[acum]++;
            acum = 0;
        }
    }
    if(acum > 2) acum = 3;
    v[acum]++;
    acum = 0;

    int max = 0;
    if(v[3] > 0) {
        std::cout << 2 << std::endl;
    } else if(v[1] == 0 && v[2] == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << v[1] + v[2]*2 << std::endl;
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << max << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
