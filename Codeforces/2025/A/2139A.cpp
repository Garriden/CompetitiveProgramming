// https://codeforces.com/contest/2139/problem/A
// Div. 2
// 500

// Maple and Multiplication

// g++ -o c c.cpp

// math
// greedy

//

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ull n, x, y, k, l, r;
    ull a, b, p;
    std::string s;
    int max = 0;

    std::cin >> a >> b;

    if(a == b) {
        std::cout << 0 << std::endl;
    } else if( (a%b == 0) || (b%a == 0) ) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << response[ii];
    //} std::cout << std::endl;

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