//https://codeforces.com/contest/2118/problem/B
// Div. 2
// 1000

// Make It Permutation

// g++ -o b b.cpp

// constructive algorithms
// permutations

// Cyclic shift using three operations.
// Good but needs to be maximum 2*n operations.
//  max n = 5.000, in my case, the operations are 15.000.
// I do three reverses per row, He does two.

// One of the operations performed on each row becomes redundant.

// Cyclic shift using two operations.
// To optimize it to 2n operations observe that performing "1n" on each row does nothing

// So at the end I will have thse same "cyclic" thing, but reversed (because I don't do the first reverse).

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    std::vector<std::string> vs;

    for(int ii = 0; ii < n; ++ii) { // row
        //vs.push_back(std::to_string(ii+1) + " " + std::to_string(cont+1) + " " + std::to_string(n));
        
        if(ii+1 < n && ii+1+1 != n) {
            vs.push_back(std::to_string(ii+1) + " " + std::to_string(ii+1+1) + " " + std::to_string(n));
        }

        if(ii >= 1) {
            vs.push_back(std::to_string(ii+1) + " " + std::to_string(1) + " " + std::to_string(ii+1));
        }
    }

    std::cout << vs.size() << std::endl;
    for(int ii = 0; ii < vs.size(); ++ii) {
        std::cout << vs[ii];
        std::cout << std::endl;
    }

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
