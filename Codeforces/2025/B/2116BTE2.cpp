//https://codeforces.com/contest/2116/problem/B
// Div. 2
// 750 ?

// Gellyfish and Baby's Breath

// g++ -o b b.cpp

// greedy
// math
// sortings

// Problem: Cannot compute 2^x, is to big.
// But no problem, just checking the exponent is enough.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    std::cin >> n;

    std::vector<ll> p(n);
    std::vector<ll> q(n);
    std::vector<ll> pRes(n, -1);
    std::vector<ll> qRes(n, -1);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> p[ii];
        //pRes[ii] = pow(2, p[ii]);
        //std::cout << pRes[ii] << " ";
    }
    //std::cout << std::endl;

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> q[ii];
        //qRes[ii] = pow(2, q[ii]);
        //std::cout << qRes[ii] << " ";
    }
    //std::cout << std::endl;


    for(int jj = 0; jj < n; ++jj) {
        ll aux = 0;
        ll aux1 = 0;
        ll aux2 = 0;
        ll max = 0;
        ll max1 = 0;
        ll max2 = 0;
        ll min = -1;
        ll minAux = -1;
        //aux1 = p[jj];
        //aux2 = q[n-1-(n-1+jj)];
        //aux = aux1 + aux2;

        //if(aux1 > max || aux2 > max) {
        //    //max1 = aux1;
        //    //max2 = aux2;
        //    //max = max1 + max2;
        //    max = std::max(aux1, aux2);
        //}
        for(int kk = 0; kk <= jj; ++kk) {
            //ll aux = pow(2, p[kk]) + pow(2, q[jj-kk]);
            aux1 = p[kk];
            aux2 = q[jj - kk];
            //aux = aux1 + aux2;
            //std::cout << "        aux1: " << aux1 << "  / aux2: " << aux2 << std::endl;
            if(aux1 >= max || aux2 >= max) {
                
                //max = std::max(aux1, aux2);
                if( (aux1 == max || aux2 == max) ) {
                    minAux = std::min(aux1, aux2);
                    //std::cout << "        minAux: " << minAux << "  / min: " << min << std::endl;
                    if(minAux > min) {
                        max1 = aux1;
                        max2 = aux2;
                        max = std::max(aux1, aux2);
                        min = minAux;
                    }
                } else {
                    min = std::min(aux1, aux2);
                    max1 = aux1;
                    max2 = aux2;
                    max = std::max(aux1, aux2);
                }

                //std::cout << "max1: " << max1 << "  / max2: " << max2 << std::endl;  

            }
            //std::cout << "max1: " << max1 << "  / max2: " << max2 << std::endl;
            //if(aux > MOD) {
            //    return;
            //}
        }
        
        //max = pow(2, max1) + pow(2, max2);
        //std::cout << "max: " << max << std::endl;
        //std::cout <<  ((1LL << max1) + (1LL << max2)) % MOD << std::endl;
        std::cout << pow(2, max1) + pow(2, max2) << std::endl;
    }

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
