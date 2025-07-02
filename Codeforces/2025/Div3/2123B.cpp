//https://codeforces.com/contest/2123/problem/b
// Div. 3
//

// Tournament

// g++ -o b b.cpp

// math

//

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k, j;
    ll a, b, p;
    std::string s;
    std::cin >> n;
    std::cin >> j >> k;

    ll max = 0;
    std::vector<int> va(n, 0);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        if(va[ii] > max) max = va[ii];
    }

    int jValue = va[j-1];

    if(k == 1) {
        if(max == jValue) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "YES" << std::endl;
    }



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
