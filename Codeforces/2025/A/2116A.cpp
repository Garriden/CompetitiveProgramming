//https://codeforces.com/contest/2116/problem/A
// Div. 2
// 500

// Gellyfish and Tricolor Pansy

// g++ -o a a.cpp

// games
// greedy

// Just notice which, if the HP or the knight is lower (min).
// Don't iterate, just check who's bigger.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> a >> b >> c >> d;

    int cont = 1;
    if(a < c) {
        c = a;
    }

    if(b < d) {
        d = b;
    }

    //while(c > 0 && d > 0) {
    //    if(cont % 2 == 1) {
    //        --d;
    //        //std::cout << "G attacks F, d = " << d << std::endl;
    //    } else {
    //        --c;
    //        //std::cout << "F attacks G, c = " << c << std::endl;
    //    }
    //    ++cont;
    //}

    if(c >= d) {
        std::cout << "Gellyfish" << std::endl;
    } else {
        std::cout << "Flower" << std::endl;
    }

    //if(d <= 0) {
    //    std::cout << "Gellyfish" << std::endl;
    //} else if(c <= 0) {
    //    std::cout << "Flower" << std::endl;
    //}
    //std::cout << "sum: " << sum << std::endl;
    //std::cout << sum << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
