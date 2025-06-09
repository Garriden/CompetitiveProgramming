//https://codeforces.com/contest/2117/problem/D
// Div. 3
//

// Retaliation

// g++ -o d d.cpp

// math

// See if new element has new diff as before.
// Check if decreasing or ascending.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;
    //std::cin >> s;



    std::vector<int> v(n);
    std::cin >> v[0];
    std::cin >> v[1];
    ll diff = v[1] - v[0];
    bool bad = false;

    for(int ii = 2; ii < n; ++ii) {
        std::cin >> v[ii];

        if(diff != (v[ii] - v[ii - 1])) {
            bad = true;
        }
    }

    if(bad) {
        std::cout << "NO" << std::endl;
        return;
    }

    // make it zeros.
    for(int ii = 0; ii < n; ++ii) {
        ll aux = -diff * (ii + 1);
        if(diff < 0) { // descendant
            aux = diff * (n - ii);
        }

        v[ii] += aux;
    }

    //for(int ii = 0; ii < n; ++ii) {
        //std::cout << v[ii] << " ";
        if(v[0] >= 0 && v[0] % (n + 1) == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "No" << std::endl;
            return;
        }
    //}

    //std::cout << "YES" << std::endl;
    //std::cout << "ascendant: " << ascendant << "  / desc: " << descendant << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
