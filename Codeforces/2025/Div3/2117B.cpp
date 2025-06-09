//https://codeforces.com/contest/2117/problem/B
// Div. 3
// 1

// Shrink

// g++ -o b b.cpp

// constructive algorithms

// Any permutation with 1 and 2 on the endas are acceptable.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    int number = 1;
    int indexL = 0;
    int indexR = n - 1;
    std::vector<int> v(n);

    while(indexL <= indexR) {
        v[indexL++] = number++;
        if(indexL <= indexR) {
            v[indexR--] = number++;
        }
    }

    for(int ii = 0; ii < n; ++ii) {
        std::cout << v[ii] << " ";
    }std::cout << std::endl;

    //std::cout << "YEs" << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << cont << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
