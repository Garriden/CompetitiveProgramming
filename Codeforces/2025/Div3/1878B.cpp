// https://codeforces.com/contest/1878/problem/B
// Div. 3
// 800 ?

// Aleksa and Stack

// g++ -o a a.cpp

// Constructive algorithms
// math
// history values

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a, k, x;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        //std::cin >> n >> k >> x;
        std::cin >> n;

        std::cout << "7 " << "11 ";

        int before2 = 7;
        int before = 11;
        int num = 12;

        for(ll ii = 2; ii < n; ++ii) {
            bool next = false;
            while(!next) {
                if( ((3*num) % (before + before2)) != 0) {
                    std::cout << num << " ";
                    next = true;
                    before2 = before;
                    before = num;
                }
                ++num;
            }
        } std::cout << std::endl;
    }

}
