//https://codeforces.com/contest/2114/problem/C
// Div. 3
// 3

// Need More Arrays

// g++ -o c c.cpp

// greedy

// Iteriate and check before variable.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;

        int cont = 1;
        
        std::cin >> a;
        int before = a;

        for(int ii = 1; ii < n; ++ii) {
            std::cin >> a;

            if(a <= before + 1) {

            } else {
                //std::cout << "a: " << a << std::endl;
                before = a;
                ++cont;
            }
        }

        //std::cout << "cont: " << cont << std::endl;
        std::cout << cont << std::endl;
    }

}
