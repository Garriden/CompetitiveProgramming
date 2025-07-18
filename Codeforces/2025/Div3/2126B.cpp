//https://codeforces.com/contest/2126/problem/B
// Div. 3
//

// No Casino in the Mountains

// g++ -o b b.cpp

// greedy.
// dp.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;

    std::vector<int> va(n, 0);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    ll aux = k;
    ll cont = 0;
    bool rest = false;

    for(int ii = 0; ii < n; ++ii) {
        if(rest) {  // restin jejeje
            rest = false;
        } else {
            if(va[ii] == 0) {
                --aux;
            } else { // va == 1
                aux = k;
            }

            if(aux == 0) {
                ++cont;
                aux = k;
                rest = true;
            }
        }
    }

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    std::cout << cont << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
