#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <bitset>
#define ll long long
using namespace std;
 
//g++ -o hola hola.cpp
 
int main() {
    ll t, n, m, CA, w, h, r, c;
    ll a;

    std::cin >> t;
    while(t--) {

        std::cin >> n >> m >> r >> c;
        ll N = n;
        ll sum = 0;
        ll cost = 0;

        //std::vector<ll> va(n);
        //std::vector<ll> vb(m);
        //std::vector<ll> maxims(n);
        int c0, r0;
        r0 = r-1;
        c0 = c-1;

        int ii = r0;
        int jj = c0;

        for(; ii < n; ++ii) {
            
            for(; jj < m; ++jj) {

                if (ii > 0) {
                        sum += 1;
                    }
                    if (jj > 0) {
                        sum += 1;
                    }
                    if (ii < r0) {
                        sum -= 1;
                    }
                    if (jj < c0) {
                        sum -= 1;
                    }

            }
            jj = 0;
        }



//cout << " right: " << right << endl;
//        for(int ii = 0; ii < n; ++ii) {
//            cout << " MAP: " << maxims[ii] << endl;
//        }


//std::cout << "cost: " << cost << std::endl;
std::cout << sum << std::endl;
        //std::cout << "sum: " << sum << std::endl;
        //std::cout << sum<< std::endl;
    }
 
}