//https://codeforces.com/contest/1894/problem/B
// Div. 2
// 750

// Two Out of Three

// g++ -o b b.cpp

// constructive algorithms

// Make a map of element Frequencies, possible candidate if appear more than three times.
// build just two element of these candidates.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    std::map<int,int> elementFrequencies;

    std::vector<int> va(n, 0);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        ++elementFrequencies[va[ii]];
    }

    if(elementFrequencies.size() < 2 || n < 2) {
        std::cout << -1 << std::endl;
        return;
    }

    int frequenciesBiggerThanOne = 0;
    int elem1 = -1;
    int elem2 = -1;
    for(auto pair : elementFrequencies) {
        //std::cout << "key: " << pair.first << "   value: " << pair.second << std::endl;
        if(pair.second > 1) {
            ++frequenciesBiggerThanOne;
            if(elem1 < 0) {
                elem1 = pair.first;
            } else {
                elem2 = pair.first;
            }
        }
    }

    int elem1Cont = 2;
    int elem2Cont = 2;
    if(frequenciesBiggerThanOne >= 2) { // yes.
        for(int ii = 0; ii < n; ++ii) {
            if(va[ii] == elem1) { // 1, 2
                if(elem1Cont-- == 1) {
                    std::cout << "2 ";
                } else {
                    std::cout << "1 ";
                }
            } else if(va[ii] == elem2) { // 1, 3
                if(elem2Cont-- == 1) {
                    std::cout << "3 ";
                } else {
                    std::cout << "1 ";
                }
            } else {
                std::cout << "1 ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << -1 << std::endl;
        return;
    }

    //std::cout << "frequenciesBiggerThanOne: " << frequenciesBiggerThanOne << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
