//https://codeforces.com/contest/2109/problem/C1
// Div. 2
// 1250

// Hacking Numbers (Easy Version)

//g++ -o a a.cpp

// interactive
// constructive algorithms
// math
// number theory
// bitmasks

// unknown integer: x. Must make it equal to given input n.
// Strategy: Force x to a known, small value, then adjust to n.
// Convert to 1 to just to know what to add or mul to get n.
// No ifs.
// Cut the posible range the better if posible. (half)

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        
        int n;
        int x;
        std::cin >> n;
        
        // n between 1 and 10^9.
        // Worst case: = 999.999.999
        std::cout<< "digit" << std::endl;
        // n [1, 81]

        // Worst case: = 79
        std::cin >> x;
        std::cout << "digit" << std::endl;
        // n [1, 16]

        // Worst case: = 16
        std::cin >> x;
        std::cout << "add -8" << std::endl;
        // n [1, 8]

        std::cin >> x;
        std::cout << "add -4" << std::endl;
        // n [1, 4]

        std::cin >> x;
        std::cout << "add -2" << std::endl;
        // n [1, 2]

        std::cin >> x;
        std::cout << "add -1" << std::endl;
        // n [1, 1]

        std::cin >> x;
        std::cout << "add "<< n - 1 << std::endl;

        std::cin >> x;
        std::cout << "!" << std::endl;

        std::cin >> x;
    }

}
