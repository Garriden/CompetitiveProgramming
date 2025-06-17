//https://codeforces.com/contest/1898/problem/B
// Div. 2
// 1250  *1500

// Milena and Admirer

// g++ -o b b.cpp

// greedy

// Tw
// new test 
// 3 
// 4 12 5 -> 2
// Ah no split by 2 but by x(3)

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    ll minAbsolute = LLONG_MAX;

    std::vector<ll> va(n + n + 2);
    std::vector<ll> dp(n + n + 2);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];

        if(va[ii] < minAbsolute) {
            minAbsolute = va[ii];
        }
    }

    if(std::is_sorted(va.begin(), va.end())){
        std::cout << 0 << std::endl;
    }

    int contInserted = 0;
    ll next = va[n - 1];
    for(int ii = n - 2; ii >= 0; --ii) {

        // Search for first lower.
        if(va[ii] > next) {
            ll maxa = va[ii];
            ll mina = 0;
            if(va[ii] < mina) {
                mina = va[ii];
            }
            
            // No need for a second for.
            ll a1 = (maxa) / 2;
            ll a2 = (maxa - 1) / 2 + 1;
            std::cout << " a1: " << a1 << "  / a2: " << a2 << "   / maxa: " << maxa << "  / next: "<<next << std::endl;
            va[ii] = a1;
            va.insert(va.begin() + ii + 1, a2);

            if(a1 < mina) {
                mina = a1;
            }
            ++contInserted;
            ++ii; // To check if the new value is still decreasing.

            // check if still decreasing.
            if(va[ii] > mina) { // 4 {2,2}
                ++ii;
            }

            //std::cout << " va: ";
            //for(int ii = 0; ii < n + n; ++ii) {
            //    std::cout << va[ii] << " ";
            //} std::cout << std::endl;

        }

        next = va[ii];
    }
    //std::cout << "contInserted: " << contInserted << std::endl;
    std::cout << contInserted << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}