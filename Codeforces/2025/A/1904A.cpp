// https://codeforces.com/contest/1904/problem/A
// Div. 2
// 500 *900

// Forked!

// g++ -o a a.cpp

// implementation
// brute force
// data structures
// set

// Stuck trying to find all possible corner cases!
// Instead of descovering a formula or stack if / else,
//  make a data structure containing all possible positions and compare

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    ll P, l, t;
    std::string s;

    ll xk, yk, xq, yq;
    std::cin >> a >> b;
    std::cin >> xk >> yk >> xq >> yq;

    ll sum = 0;
    std::set<std::pair<ll, ll> > posiblePositions;

    posiblePositions.insert({xk+a, yk+b});
    posiblePositions.insert({xk+a, yk-b});
    posiblePositions.insert({xk-a, yk+b});
    posiblePositions.insert({xk-a, yk-b});
    posiblePositions.insert({xk-b, yk-a});
    posiblePositions.insert({xk-b, yk+a});
    posiblePositions.insert({xk+b, yk-a});
    posiblePositions.insert({xk+b, yk+a});

    //for(auto s : posiblePositions) {
    //    std::cout << s.first << " " << s.second << std::endl;
    //}

    if(posiblePositions.count({xq+a, yq+b})) ++sum;
    if(posiblePositions.count({xq+a, yq-b})) ++sum;
    if(posiblePositions.count({xq-a, yq+b})) ++sum;
    if(posiblePositions.count({xq-a, yq-b})) ++sum;
    if(a != b) {
        if(posiblePositions.count({xq-b, yq-a})) ++sum;
        if(posiblePositions.count({xq-b, yq+a})) ++sum;
        if(posiblePositions.count({xq+b, yq-a})) ++sum;
        if(posiblePositions.count({xq+b, yq+a})) ++sum;
    }

    //std::cout << "max: " << max << std::endl;
    std::cout << sum << std::endl;
    //std::cout << n << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        /*
        // Watch test failing trick. Wrong answer  Checker comment
        // wrong answer 1683rd numbers differ - expected: '2', found: '0'
        int TOKEN = 1683; // [1683th token]
        int TEST_T_INPUT = 69; // Second test failing, t = 10000
        
        if(t == (TEST_T_INPUT - 1)) {
            std::cout << "AmInTheFailingTest." << std::endl;
            // Now I'm at test 2.
            // I just want the correct token.
            int index = 1;
            while(index++ <= TOKEN) {
                // Simulate the inputs
                ll n;
                std::string s;
                std::cin >> n >> s;

                if(index == (TOKEN - 1)) {
                    std::string out = "n:_" + std::to_string(n) + "_/_s:" + s;
                    std::cout << out << std::endl;
                }
                if(index == (TOKEN)) {
                    std::string out = "n:_" + std::to_string(n) + "_/_s:" + s;
                    std::cout << out << std::endl;
                }

            }
        } else {
            solve();
        }
        */
        solve();
    }

}
