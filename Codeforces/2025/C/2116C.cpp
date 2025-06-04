//https://codeforces.com/contest/2116/problem/C
// Div. 2
// 1250 ?

// NOT GOOD

// g++ -o c c.cpp

// gcd
// Time limit exceeded.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> n;

    std::vector<ll> va(n);
    std::vector<bool> present(5000 + 1, false);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        present[va[ii]] = true;
    }

    ll gcdAll = 0;
    if(present[1]) { // If there is a 1, gcd is 1.
        //std::cout << "1 present " << std::endl;
        gcdAll = 1;
    } else { 
        // If there is two consecutive numbers gcd is 1.
        bool consecutive = false;
        for(int ii = 1; !consecutive && ii < n; ++ii) {
            if(present[va[ii]] && present[va[ii]-1]) {
                consecutive = true;
            }
        }

        if(consecutive) { // If there is two consecutive numbers gcd is 1.
            //std::cout << "Consecutive present " << std::endl;
            gcdAll = 1;
        } else { // else, Find gdc.
            //std::cout << "Find gdc manually " << std::endl;
            gcdAll = va[0];
            for(int ii = 1; ii < n; ++ii) {
                gcdAll = std::gcd(gcdAll, va[ii]);
            }
        }
    }
    //std::cout << "GCD of all numbers is: " << gcdAll << std::endl;

    ll cont = 0;
    // if gcd exist as a number, I just need to convert all numbers to that one.
    if(present[gcdAll]) {
        for(int ii = 0; ii < n; ++ii) {
            if(va[ii] != gcdAll) {
                ++cont;
            }
        }
    } else { // Comença la festa.
        // So zetta slow.
        int minGcdPair = INT_MAX; // Initialize with a large value
        while(minGcdPair > gcdAll) {
            ll gcdMinIndex = -1;
            for(int i = 0; i < va.size(); ++i) {
                for(int j = i + 1; j < va.size(); ++j) {
                    ll gcdAux = std::gcd(va[i], va[j]);
                    if(gcdAux < minGcdPair) {
                        minGcdPair = gcdAux;
                        gcdMinIndex = i;
                    }
                }
            }
            if(gcdMinIndex >= 0) {
                va[gcdMinIndex] = minGcdPair;
            }
            //std::cout << "Minimum pairwise GCD is: " << minGcdPair << std::endl;
            ++cont;
        }
        
    
        // I just need to convert all numbers to that one.
        for(int ii = 0; ii < n; ++ii) {
            if(va[ii] != gcdAll) {
                ++cont;
            }
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
