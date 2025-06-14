//https://codeforces.com/contest/1895/problem/B
// Educational Div. 2
// *800

// Points and Minimum Distance

// g++ -o a a.cpp

// greedy
// math
// sortings

// Sort and see pairs.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    std::vector<int> va(n*2, 0);
    for(int ii = 0; ii < n*2; ++ii) {
        std::cin >> va[ii];
    }

    std::sort(va.begin(), va.end());

    int x1 = std::abs(va[0] - va[n-1]);
    int y1 = std::abs(va[n*2 - 1] - va[n]);
    //std::cout << "va[0]: " << va[0] << "  va[n*2 - 1]: " << va[n*2 - 1] << std::endl;
    //std::cout << "va[n-1]: " << va[n-1] << "   va[n]: " <<  va[n] << std::endl;
    int distance = x1 + y1;
    //std::cout << "distance: " << distance << std::endl;
    std::cout << distance << std::endl;
    for(int ii = 0; ii < n; ++ii) {
        //std::cin >> va[ii];
        std::cout << va[ii] << " " << va[n*2 - 1 - ii] << std::endl;
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
