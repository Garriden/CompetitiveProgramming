//https:/d
// Div. 
// 

// te room

// g++ -o b b.cpp

// bitms

// 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    ll P, l, t;
    ll iene;

    std::cin >> iene >> P >> l >> t;
    n = iene;

    // Find to maximize if can put all the tasks into a day.
    ll maximizeDays = ((n - 8) / 14) + 1;
    if(n < 8) maximizeDays = 0;
    ll maximizeSecondDays = ((n - 1) / 7) + 1 - maximizeDays;
    if(n < 8 && n > 0) maximizeSecondDays = 1;

    ll maxPoints = (t*2 + l);
    //std::cout << "maximizeDays: " << maximizeDays << "   maximizeSecondDays: " << maximizeSecondDays << std::endl;

    while(n > 0 && maximizeDays > 0 && P > 0) {
        //std::cout << "DAY 1" << "  P: " << P << " - rest: " << maxPoints << std::endl;
        P -= maxPoints; // maximized tasks study day.
        --n;
        --maximizeDays;
        --maximizeSecondDays;
    }
    while(n > 0 && maximizeSecondDays > 0 && P > 0) {
        //std::cout << "DAY 2" << "  P: " << P << " - rest: " << (l+t) << std::endl;
        P -= (l+t); // normal task study day.
        --n;
        --maximizeSecondDays;
    }
    while(n > 0 && P > 0) {
        //std::cout << "DAY 3" << "  P: " << P << " - l: " << (l) << std::endl;
        P -= l; // study day without tasks.
        --n;
    }
    //std::cout << "attendance: " << attendance << std::endl;
    std::cout << n << std::endl;
    //std::cout << n - attendance << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
