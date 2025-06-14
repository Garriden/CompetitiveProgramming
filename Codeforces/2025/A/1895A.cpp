//https://codeforces.com/contest/1895/problem/A
// Educational Div. 2
// *800

// Treasure Chest

// g++ -o a a.cpp

// math

// Just iterate.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s;
    int chest;
    int key;
    int stamina;
    std::cin >> chest >> key >> stamina;

    //std::vector<int> va(n, 0);
    //for(int ii = 0; ii < n; ++ii) {
    //    std::cin >> va[ii];
    //}

    if(key < chest) {
        std::cout << chest << std::endl;
        return;
    }

    if(chest + stamina >= key) {
        std::cout << key << std::endl;
        return;
    } else {
        chest += stamina;
        std::cout << chest + (key - chest) * 2 << std::endl;
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
