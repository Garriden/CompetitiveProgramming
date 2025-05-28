//https://codeforces.com/contest/2114/problem/A
// Div. 3
// 1

// Square Year

// g++ -o a a.cpp

// math
// brute force

//  

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, p;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> s;
        std::size_t pos = 4;
        int num = std::stoi(s, &pos);
        double squareRoot = std::sqrt(num);


        if( std::floor(squareRoot) == std::ceil(squareRoot) ) { // has residue.
            std::cout << squareRoot << " 0" << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }

        //std::cout << "sum: " << sum << std::endl;
        //std::cout << sum << std::endl;

    }

}
