//https://codeforces.com/contest/2117/problem/D
// Div. 3
//

// Retaliation

// g++ -o d d.cpp

// math

// M

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


    // map ?
    
    bool descendant = true;
    bool ascendant = true;
    //bool diff = true;

    std::vector<int> v(n);
    std::cin >> v[0];
    int before = v[0];
    for(int ii = 1; ii < n; ++ii) {
        std::cin >> v[ii];
        
        if(before > v[ii]) {
            ascendant = false;
        } else {
            descendant = false;
        }
    }

    if(ascendant || descendant) {

        while(v[0] > 0) {


            if(ascendant) {
                for(int ii = 0; ii < n; ++ii) {
                    v[ii] -= (ii + 1);
                }

                //for(int ii = 0; ii < n; ++ii) {
                //    std::cout << v[ii] << " ";
                //} std::cout << std::endl;


                if(v[0] > v[1]) { // check descendant.
                    ascendant = true;
                    descendant = true;
                    before = v[0];
                    for(int ii = 1; ii < n; ++ii) {
                        if(before > v[ii]) {
                            ascendant = false;
                        } else {
                            descendant = false;
                        }
                    }
                }

            } else { // descendant

                for(int ii = 0; ii < n; ++ii) {
                    v[ii] -= (n-ii);
                }

                //for(int ii = 0; ii < n; ++ii) {
                //    std::cout << v[ii] << " ";
                //} std::cout << std::endl;

                if(v[0] < v[1]) { // check ascendant.
                    ascendant = true;
                    descendant = true;
                    before = v[0];
                    for(int ii = 1; ii < n; ++ii) {
                        if(before > v[ii]) {
                            ascendant = false;
                        } else {
                            descendant = false;
                        }
                    }
                    
                }
            }

            //std::cout << "ascendant: " << ascendant << "  / desc: " << descendant << std::endl;

        }
        

    } else {
        //std::cout << "YEs" << std::endl;
        std::cout << "no" << std::endl;
        return;
    }

    for(int ii = 0; ii < n; ++ii) {
        if(v[ii] == 0) {

        } else {
            std::cout << "No" << std::endl;
            return;
        }
    }

    std::cout << "YES" << std::endl;
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
