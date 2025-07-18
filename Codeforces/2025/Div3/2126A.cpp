//https://codeforces.com/contest/2126/problem/A
// Div. 3
//

// Only One Digit

// g++ -o a a.cpp

// Brute force.
// Implementation.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

ll catchDigits(ll x) {
    ll min = 9;

    while(x > 9) {
        if(min > (x % 10)) {
            min = (x % 10);
        }
        x /= 10;
    }

    if(min > (x % 10)) {
        min = (x % 10);
    }

    return min;
}

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    std::cout << catchDigits(n) << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
