//https://codeforces.com/contest/2109/problem/C3
// Div. 2
// 1250 + 750

// Hacking Numbers (Hard Version)

//g++ -o a a.cpp

// interactive
// constructive algorithms
// math
// number theory
// bitmasks

// unknown integer: x. Must make it equal to given input n.
// Strategy: Force x to a known, small value, then adjust to n.
// Convert to 1 to just to know what to add or mul to get n.

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {

        for(ll ii = 0; ii < 1000; ++ii) {
            std::cout << ii * 999999999 << std::endl;
        }
        
        int n;
        int x;
        std::cin >> n;
        
        // n between 1 and 10^9.
        // Worst case: = 999.999.999
        std::cout<< "mul 999999999" << std::endl;

        // Apply "digit" → x becomes exactly 81.
        std::cin >> x;
        std::cout << "digit" << std::endl;

        std::cin >> x;
        if(n != 81) {
            std::cout << "add " << n - 81 << std::endl;
            std::cin >> x;
        }

        std::cout << "!" << std::endl;
        std::cin >> x;
    }

}
