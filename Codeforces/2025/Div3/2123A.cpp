//https://codeforces.com/contest/2123/problem/A
// Div. 3
//

// Blackboard Game

// g++ -o a a.cpp

// math

// 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    if(n % 2 == 1) {
        std::cout << "ALICE" << std::endl;
    } else {
        if(n % 4 == 0) {
            std::cout << "BOB" << std::endl;
        } else {
            std::cout << "Alice" << std::endl;
        }
        
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
