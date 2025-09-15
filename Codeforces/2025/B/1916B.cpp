// https://codeforces.com/contest/1916/problem/B
// Div
// 750  *1000

// Two Divisors

// g++ -o b b.cpp

// math
// number theory

// Smallest prime factors...
// The largest divisor of x is x / smallest prime factor.
// if you multiply a and b, you are multiplying x twice.

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
    

    std::cin >> a >> b;

    if(a == 1) {
        std::cout << b * b << std::endl;
    } else if(b == 1) {
        std::cout << a * a << std::endl;
    } else {
        ll smaller = a;
        ll larger = b;

        if(a > b) {
            smaller = b;
            larger = a;
        }

        if((larger % smaller == 0)) {
            std::cout << b * (b / a) << std::endl;
        } else {
            ll gesede = std::gcd(a, b);
            std::cout << (a * b) / (gesede) << std::endl;
        }


        
    }

    //std::cout << a * b << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
