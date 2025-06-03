//https://codeforces.com/contest/1884/problem/B
// Div. 2
// 1000

// Haunted house

// g++ -o b b.cpp

// greedy
// math
// two pointers
// DP ?

// Binary number by 2^x, just check if in that resition there's an one.
// Then count the number of zeroes.
// Then for each zero, swap, and keep a sum (DP). vetor of where the zeros are positioned.
// For each zero, sum the difference from the vector zero postions.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;
    std::cin >> s;

    //std::cout << sumDigits(n) << std::endl;

    std::vector<ll> zerosPositions;
    ll zeros = 0;
    ll ones = 0;
    for(ll ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == '0') {
            ++zeros;
            zerosPositions.push_back(ii);
        } else {
            ++ones;
        }
    }

    //std::cout << "zerosPositions. ";
    //for(ll ii = 0; ii < zerosPositions.size(); ++ii) {
    //    std::cout << zerosPositions[ii] <<  " ";
    //} std::cout << std::endl;

    //std::cout << "zeros: " << zeros << std::endl;
    ll swaps = 0;
    for(ll ii = 0; ii < zeros; ++ii) {
        // Check how many swaps.
        //if(s[s.size() - 1 - ii] != '0') { // if not a zero, swap.
            //std::cout << "posii: " << s.size() - 1 - ii <<  " shoud be 0."<< std::endl;
            ll zeroPos = zerosPositions[zerosPositions.size() - 1];
            //std::cout << "zeroPos: " << zeroPos <<  "   / sum swaps:" << s.size() - 1 - ii - (zeroPos) << std::endl;
            swaps += s.size() - 1 - ii - (zeroPos);
            zerosPositions.pop_back();
        //} else {
            //zerosPositions.pop_back();
        //}

        std::cout << swaps << " ";
    }

    for(ll ii = 0; ii < ones; ++ii) {
        std::cout << "-1 ";
    }

    std::cout << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
