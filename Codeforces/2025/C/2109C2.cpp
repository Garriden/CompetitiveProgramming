//https://codeforces.com/contest/2109/problem/C2
// Div. 2
// 1250 + 500

// Hacking Numbers (Medium Version)

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

// If you multiply any integer (random or not) by 9, the result will always be divisible by 9.
// Concept: A number is divisible by 3 (or 9), the sum of its digits is divisible by 3 (or 9).

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
        std::cout<< "mul 9" << std::endl;
        // If you multiply any integer (random or not) by 9, the result will always be divisible by 9.

        // Worst case: = 999.999.999 * 9 = 8.999.999.991
        std::cin >> x;
        std::cout << "digit" << std::endl;
        // Concept: A number is divisible by 3 (or 9), the sum of its digits is divisible by 3 (or 9).
        // n divisible by 9.
        // n [9,18,27,36,45,54,63,72,81]

        std::cin >> x;
        std::cout << "digit" << std::endl;
        // n [9]

        std::cin >> x;
        std::cout << "add "<< n - 9 << std::endl;

        std::cin >> x;
        std::cout << "!" << std::endl;

        std::cin >> x;
    }

}
