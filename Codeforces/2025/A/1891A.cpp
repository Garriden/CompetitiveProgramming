//https://codeforces.com/contest/1891/problem/A
// Div. 2
// 1

// Sorting with Twos

// g++ -o a a.cpp

// constructive algorithms
// sortings

// Iterate every power of 2 and check order.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s, t;
    std::cin >> n;

    std::vector<int> va(n);
    //std::vector<int> vaOrdered(n);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    //vaOrdered = va;
    int m = static_cast<int>(std::log2(n));
    //std::cout << "m: " << m << std::endl;
    //std::is_sorted(va.begin(), va.end());
    if(std::is_sorted(va.begin() + 2, va.end())) {
        std::cout << "Yes" << std::endl;
        return;
    }

    int shift = std::exp2(m);
    if(shift > n) {
        shift = n;
    }
    //std::cout << "shift: " << shift << std::endl;

    if(!std::is_sorted(va.begin() + shift, va.end())) {
        std::cout << "No" << std::endl;
        return;
    }

    for(int ii = 1; ii < m; ++ii) {
        int realIndex = std::exp2(ii);
        int before = va[realIndex];
        int RightWallIndex = std::exp2(ii + 1);
        for(int jj = realIndex + 1; jj < RightWallIndex; ++jj) {
            //std::cout << "before: " << before << "  / va[jj]: " << va[jj] << std::endl;
            if(va[jj] < before) {
                std::cout << "nO" << std::endl;
                return;
            }
            before = va[jj];
        }
        //std::cout << std::endl;
    }


    std::cout << "yeS" << std::endl;

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
