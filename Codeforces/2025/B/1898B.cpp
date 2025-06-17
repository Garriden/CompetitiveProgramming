//https://codeforces.com/contest/1898/problem/B
// Div. 2
// 1250  *1500

// Milena and Admirer

// g++ -o b b.cpp

// greedy
// math

// new test 
// 3 
// 4 12 5 -> 2
// Ah no split by 2 but by x(3)

// Think about spliting it into more parts.
// Don't need to insert new elements in the array,
// just substitute the position with all the parts remaining.
// Increase cont with those parts.

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
            ll div = (va[ii] - 1) / next;
            va[ii] /= (div + 1);
            contInserted += div;
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
