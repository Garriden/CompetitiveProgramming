//https://codeforces.com/contest/1899/problem/B
// Div. 3
// 2  *1100

// 250 Thousand Tons of TNT

// g++ -o b b.cpp

// brute force
// implementation
// number theory

// Tests are lying!

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    std::vector<ll> va(n);
    
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    ll absoluteMaxDiff = 0;
    for(int ii = 1; ii < (n / 2) + 1; ++ii) {
        if(n % ii == 0) { // if divisible
            int cont = ii;
            ll sum = 0;
            ll max = 0;
            ll min = LLONG_MAX;
            for(int jj = 0; jj < n; ++jj) {
                
                sum += va[jj];
                --cont;

                if(cont == 0) {
                    cont = ii;
                    if(sum > max) {
                        max = sum;
                    }
                    if(sum < min) {
                        min = sum;
                    }

                    sum = 0;
                }
            }
            ll diff = max - min;
            //std::cout << " diff: " << diff << std::endl;
            if(diff > absoluteMaxDiff) {
                absoluteMaxDiff = diff;
            }
        }

    }

    //std::cout << " absoluteMaxDiff: " << absoluteMaxDiff << std::endl;
    std::cout << absoluteMaxDiff << std::endl;
    
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
