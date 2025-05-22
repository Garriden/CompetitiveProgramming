// https://codeforces.com/contest/1875/problem/A
// Div. 2
// 500 *900

// Jellyfish and Undertale

// g++ -o a a.cpp

// brute force
// greedy

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, x;
    ll a, b, k;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> a >> b >> n;
        ll sum = b - 1;
        
        //std::vector<int> v(n, 0);
        for(int ii = 0; ii < n; ++ii) {
            //std::cin >> v[ii];
            std::cin >> x;
            if(x >= a) {
                x = a - 1;
            }
            sum += x;
        }
        ++sum;
        std::cout << sum << std::endl;

    }

}
