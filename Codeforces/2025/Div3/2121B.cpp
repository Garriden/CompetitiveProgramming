// https://codeforces.com/contest/2121/problem/B
// Div. 3
//

// Above the clouds

// g++ -o a a.cpp

// greedy
// strings

// Map and check if already exists.
// special case for first and last position.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;
    std::cin >> s1;

    ll acont = 0;
    ll bcont = 0;

    //std::vector<ll> va(n);
    //for(int ii = 0; ii < n; ++ii) {
    //    std::cin >> va[ii];
    //}

    bool exists = false;
    std::set<char> mySet;
    mySet.insert(s1[0]);
    mySet.insert(s1[n-1]);
    for(int ii = 1; ii < n-1; ++ii) {
        //std::cout << "s1ii: " << s1[ii] << std::endl;
        if(!mySet.insert(s1[ii]).second) { // already exists (Cannot insert)
            //std::cout << "already exisstst" << std::endl;
            exists = true;
            break;
        }
    }

    if(exists) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
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
