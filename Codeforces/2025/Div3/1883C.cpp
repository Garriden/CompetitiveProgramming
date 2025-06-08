//https://codeforces.com/contest/1883/problem/C
// Div. 3
// 1500  *1000

// Raspberries

// g++ -o c c.cpp

// math
// dp ?

// Notice 2 ≤ k ≤ 5
//  the product of the numbers will be divisible by k if any number in the array is divisible by k
// k == 4 special case

//    while((va[ii] + j) % k != 0)  ++j;

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> k;
    //std::cin >> s;

    std::vector<int> va(n);
    int minDiff = INT_MAX;
    bool divisible = false;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        if(va[ii] % k == 0) {
            divisible = true;
        } else { // not divisible, increment
            int j = 0;
            while((va[ii] + j) % k != 0) {
                ++j;
            }
            minDiff = std::min(minDiff, j);
        }

    }

    if(!divisible && k == 4) {
        int even = 0;
        for(int jj = 0; jj < n; ++jj) {
            if(va[jj] % 2 == 0) {
                ++even;
            }
        }
        minDiff = std::min(minDiff, std::max(2 - even, 0));
    }


    if(divisible) {
        std::cout << 0 << std::endl;
    } else {
        //std::cout << "minDiff: " << minDiff << std::endl;
        std::cout << minDiff << std::endl;
    }

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
