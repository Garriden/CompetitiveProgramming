//https://codeforces.com/contest/2113/problem/A
// Div. 2
// 500

// Shashliks

// g++ -o a a.cpp

// greedy
// math

// Two whiles into a formula.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> k >> a >> b >> x >> y;

    ll sum = 0;
    ll max = LLONG_MIN;
    ll min = LLONG_MAX;
    ll cont1 = 0;
    ll cont2 = 0;

    min = x;
    ll tope = a;
    ll minImpostor = y;
    ll topeImpostor = b;
    if(y < x) {
        min = y;
        tope = b;
        minImpostor = x;
        topeImpostor = a;
    }


    if(k >= tope) cont1 = (k - tope) / min + 1; // + 1 needed bacause the = on the loop.
    //std::cout << " cont1: " << cont1 << std::endl;
    k -= (cont1 * min);
    
/*
    while(k >= topeImpostor) {
        k -= minImpostor;
        ++cont2;
    }
    */
    //std::cout << "   new k: " << k << std::endl;
    if(k >= topeImpostor) {
        cont2 += (k - topeImpostor) / minImpostor + 1;
    }
    //std::cout << " cont2: " << cont2 << std::endl;
    std::cout << cont1 + cont2 << std::endl;

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
