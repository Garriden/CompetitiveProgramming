// https://codeforces.com/contest/1914/problem/B
// Div. 3
//  *800

// Preparing for the Contest

// g++ -o b b.cpp

// costructive algorithms
// math

// Read the problem carefully.
// Find and test the right solution!
// I implemented this problem wrongly two times.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 0;

    std::cin >> n >> k;

    if(k == 0) {
        for(int ii = n; ii > 0; --ii) {
            std::cout << ii << " ";
        } std::cout << std::endl;
    } else if(k*2 > n) {
        std::cout << 1 << " ";

        for(int ii = n - k + 1; ii <= n; ++ii) {
            std::cout << ii << " ";
        }

        for(int ii = n - k; ii > 1; --ii) {
            std::cout << ii << " ";
        }

    
    } else {
        std::cout << 1 << " ";

        int upperIndex = n; // 6 5
        int decrementUpperIndex = (k); // decrement just k times.
        int lowerIndex = n - k; // 4 3 2 1
        int decrementLowerIndex = (n - k); // decrement just n-k times.
        int lowerLimit = 1;


        while(decrementUpperIndex > 0 || decrementLowerIndex > lowerLimit) {
            if(decrementUpperIndex > 0) {
                std::cout << upperIndex << " ";
                --upperIndex;
                --decrementUpperIndex;
            }

            if(decrementLowerIndex > lowerLimit) {
                std::cout << lowerIndex << " ";
                --lowerIndex;
                --decrementLowerIndex;
            }
        }

        std::cout << std::endl;
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
