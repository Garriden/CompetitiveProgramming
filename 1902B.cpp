//https://codeforces.com/contest/1902/problem/B
// Div. 2
// *1100

// Getting Points

// g++ -o b b.cpp

// brute force
// gready
// binary search?

// Find the formula to find maximizing days -> 8, 15, 22..
//  Second maximized days -> 1, 15 ...
// Decrement n with while bucles... To expensive...
// Transform whiles into formulas.
// Translate while condition into number of iterations:
//     min(condition1 & condition2 & condition3(Points))

// This Points are: Points / (decrement), but the real formula is:
//        ll aux = (P + decrement - 1) / decrement;

// This is a ceiling division. I need to round the result up to the nearest whole number.
// This clever trick adds a small number (maxPoints - 1) to the numerator.
//  If there's any remainder from the division, this addition is enough to "push" 
//  the numerator to the next multiple of the denominator, thus causing the division to round up.


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

    ll aux = (P + maxPoints - 1) / maxPoints;
    ll its = std::min({(long long)n, (long long)maximizeDays, aux});
    if(its > 0) {
        P -= (its * maxPoints);
        maximizeSecondDays -= its;
        n -= its;
    }
    //std::cout << "DAYsy" << "  P: " << P << " - rest: " << maxPoints << std::endl;
    //while(n > 0 && maximizeDays > 0 && P > 0) {
        //std::cout << "DAY 1" << "  P: " << P << " - rest: " << maxPoints << std::endl;
    //    P -= maxPoints; // maximized tasks study day.
    //    --n;
    //    --maximizeDays;
    //    --maximizeSecondDays;
    //}


    aux = (P + (l+t) - 1) / (l+t);
    its = std::min({(long long)n, (long long)maximizeSecondDays, aux});
    if(its > 0) {
        P -= (its * (l+t));
        n -= its;
    }
    //while(n > 0 && maximizeSecondDays > 0 && P > 0) {
        //std::cout << "DAY 2" << "  P: " << P << " - rest: " << (l+t) << std::endl;
    //    P -= (l+t); // normal task study day.
    //    --n;
    //    --maximizeSecondDays;
    //}



    aux = (P + l - 1) / l;
    its = std::min({(long long)n, aux});
    if(its > 0) {
        P -= (its * l);
        n -= its;
    }
    //while(n > 0 && P > 0) {
        //std::cout << "DAY 3" << "  P: " << P << " - l: " << (l) << std::endl;
    //    P -= l; // study day without tasks.
    //    --n;
    //}
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
