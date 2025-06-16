// https://codeforces.com/contest/1894/problem/C
// Div. 2
// 1500 *1400

// Anonymous Informant
// Wrong answer!
// Didn't understood the assignment well.
// Tests cases were a lie.

// g++ -o c c.cpp

// constructive algorithms
// graphs
// implementation

// More tests cases than described in the announcement.
// I thought jus cycling the vector was enough (or just an oparation checking it).

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;
    std::cin >> k;



    std::vector<ll> vb(n);
    for(ll ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
    }


    // shift (k % n) times to the right.
    ll shifts = k % n;
    //std::rotate(vb.begin(), vb.begin() + (vb.size() - (shifts)), vb.end());

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << vb[ii] << " ";
    //} std::cout << std::endl;

    for(ll ii = 0; ii < n; ++ii) {
        if(vb[ii] == ((ii+shifts) % n)+1) {
        //if(vb[ii] == ii + 1) {
            //std::cout << "Fixed point: " << ((ii+shifts) % n)+1 << std::endl;
            std::cout << "Yes" << std::endl;
            return;
        }
    }

    std::cout << "No" << std::endl;

    //std::cout << "frequenciesBiggerThanOne: " << frequenciesBiggerThanOne << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        // Watch test failing trick.
        /*
        if(t == (10000 - 32)) {  // but N: found [137th token]
            ll n, x, y, k;
            ll a, b, p;
            std::string s1;
            std::cin >> n;
            std::cin >> k;
        
            std::vector<ll> vb(n);
            for(ll ii = 0; ii < n; ++ii) {
                std::cin >> vb[ii];
            }
            std::string out = "n:_" + std::to_string(n) + "_/_k:" + std::to_string(k);
            for(ll ii = 0; ii < n; ++ii) {
                out += "-" + std::to_string(vb[ii]);
            }
            //std::string out = t;
            std::cout << out << std::endl;
        }
        */

        solve();
    }

}
