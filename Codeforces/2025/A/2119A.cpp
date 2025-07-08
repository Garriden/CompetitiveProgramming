// https://codeforces.com/contest/2119/problem/A
// Div. 2
// 500

// Add or XOR

// g++ -o a a.cpp

// math
// greedy

// XOR tricks.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k, j;
    ll a, b, p;
    std::string s;
    std::cin >> a >> b >> x >> y;

    ll result = (b - a) * x; // first try, just add 1 until reaches next number.

    if(a == b) {
        std::cout << 0 << std::endl;
        return;
    } else if(a > b) {
        if((a ^ 1) == b) {
            std::cout << y << std::endl;
            return;
        } else if((a ^ 1) > b) {
            std::cout << -1 << std::endl;
            return ;
        }
    }

    ll aux = a;
    ll res = 0;
    for(int ii = 0; aux < b; ++ii) {
        if(x < y) {
            ++aux;
            res += x;
        } else {
            ll auxAux = aux;
            if((aux ^ 1) > auxAux) {
                aux = aux ^ 1;
                res += y;
            } else {
                ++aux;
                res += x;
            }
            //std::cout << "aux: " << aux << std::endl;
        }
    }

    std::cout << std::min(result, res) << std::endl;

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << response[ii];
    //} std::cout << std::endl;


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
