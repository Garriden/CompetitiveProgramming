// https://codeforces.com/contest/2123/problem/b
// Div. 3
//

// Prefix Min and Suffix Max

// g++ -o c c.cpp

// data structures

// First value, last vaule, min, max, iterate trhoug local mins and maxs, look for repetitions.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k, j;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    ll max = 0;
    ll min = LLONG_MAX;
    ll maxIndex = 0;
    ll minIndex = 0;
    std::vector<int> va(n, 0);
    std::vector<int> vMins(n, 0);
    std::vector<int> vMaxs(n, 0);
    std::vector<int> response(n, 0);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];

        if(va[ii] < min) {
            min = va[ii];
            minIndex = ii;
            response[ii] = 1;
        }
        vMins[ii] = min;
    }

    for(int ii = n-1; ii >= 0; --ii) {
        if(va[ii] > max) {
            max = va[ii];
            maxIndex = ii;
            response[ii] = 1;
        }
        vMins[ii] = max;
    }



    ll firstValue = va[0];
    ll lastValue = va[n-1];

    response[minIndex] = 1;
    response[maxIndex] = 1;





    for(int ii = 0; ii < n; ++ii) {
        std::cout << response[ii];
    } std::cout << std::endl;


    //std::cout << "max: " << max << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << max << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
