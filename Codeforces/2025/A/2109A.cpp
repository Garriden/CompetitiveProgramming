//https://codeforces.com/contest/2109/problem/A
// Div. 2
// 500

// It's time to duel

//g++ -o a a.cpp

// Implementation
// Two Pointers ?

// Can't be two consecutive zeroes.
// One player must report at least a zero.

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        double n;
        std::cin >> n;
        std::vector<int> v(n);

        bool liarFound = false;
        std::cin >> a;
        ll aBefore = a;
        ll firstA = a;
        bool zeroFound = false;
        for(int ii = 1; ii < n; ++ii) {
            std::cin >> a;
            if(!liarFound) {
                //std::cout << "aBefore: " << aBefore << "    a: " << a << std::endl;
                if(aBefore == 0 && a == 0) { 
                    liarFound = true;
                } else if(a == 0) {
                    zeroFound = true;
                }
                aBefore = a;
            }
        }

        if(!zeroFound && firstA == 1) {
            std::cout << "YES" << std::endl;
        } else {
            if(liarFound) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

}