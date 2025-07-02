//https://codeforces.com/contest/1901/problem/A
// Div. 2
//  *800

// Line Trip

// g++ -o a a.cpp

// greedy
// math

// Watch last element (retornar).

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> x;

    std::vector<int> va(n, 0);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    int max = 0;
    int cont = 0;
    int vIndex = 0;
    for(int ii = 0; ii < x; ++ii) {
        //std::cout << "ii: " << ii << "  / max: " << max << "  / va[vInde<]: " <<  va[vIndex] << std::endl;
        ++cont;
        if((vIndex < va.size()) && ((ii+1) == va[vIndex])) {
            ++vIndex;

            if(cont > max) {
                max = cont;
            }

            cont = 0;
        }
    }

    if((cont * 2) > max) {
        max = cont * 2;
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    std::cout << max << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
