// https://codeforces.com/contest/2121/problem/A
// Div. 3
//

// Letter Home

// g++ -o a a.cpp

// brute force
// math

// implementation, ifs

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k, s;
    ll a, b, p;
    std::string s1;
    std::cin >> n >> s;

    ll acont = 0;
    ll bcont = 0;

    std::vector<ll> va(n);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    ll cont = 0;
    ll right = std::abs(va[n-1] - s);
    ll left = std::abs(va[0] - s);
    if(left < right) { // go left first
        if(s > va[n-1]) {
            cont += (s - va[0]);
            //std::cout << "L k> cont2: " << cont << std::endl;
        } else if(s < va[0]) {
            cont += (va[n-1] - s);
            //std::cout << "L kpeitta cont2: " << cont << std::endl;
        } else {
            cont += (s - va[0]);
            //std::cout << "L cont1: " << cont << std::endl;
            cont += (va[n-1] - va[0]);
            //std::cout << "L cont2: " << cont << std::endl;
        }
    } else {
        if(s > va[n-1]) {
            cont += (s - va[0]);
            //std::cout << "R k> cont2: " << cont << std::endl;
        }  else if(s < va[0]) {
            cont += (va[n-1] - s);
            //std::cout << "RR kpeitta cont2: " << cont << std::endl;
        } else {
            cont += (va[n-1] - s);
            //std::cout << "R cont1: " << cont << std::endl;
            cont += (va[n-1] - va[0]);
            //std::cout << "R cont2: " << cont << std::endl;
        }
    }

    //std::cout << "cont: " << cont << std::endl;
    std::cout << cont << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
