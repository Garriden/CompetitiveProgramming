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

        std::cin >> n >> m;// >> r >> c;
        ll N = n;
        ll sum = 0;
        ll cost = 0;

        std::vector<ll> va(n);
        std::vector<ll> vb(m);
        std::vector<ll> maxims(n);

        for(ll ii = 0; ii < n; ++ii) {
            cin >> va[ii];
        }

        for(ll ii = 0; ii < m; ++ii) { //ordered big to small
            cin >> vb[ii];
        }


        ll right = m-1;
        for(ll ii = n-1; ii >=0; --ii) {
            for(ll jj = right; jj >=0; --jj) {
                if(va[ii] <= vb[jj]) {
                    // Do nothing
                } else {
                    right--;
                }
            }
            maxims[ii] = right;
        }

//cout << " right: " << right << endl;
//        for(int ii = 0; ii < n; ++ii) {
//            cout << " MAP: " << maxims[ii] << endl;
//        }

        if(right < 0) {
            sum = -1;
            cost = -1;
        } else {

            ll ii = 0;
            ll k = 0;

            bool type2 = false;
            while(ii < N) {

                if(type2) {
                    type2 = false;

                    cost += m-(maxims[ii]+1);
                    sum = 0;

                } else {

                    sum += va[ii];

                    if(sum>vb[maxims[ii]]) {
                        sum -= va[ii];
                        ii -= 2;
                        type2 = true;

                    }

                }

                ii++;
            }

            if(sum > 0 or type2) cost += m-(maxims[ii-1]+1);

        }

//std::cout << "cost: " << cost << std::endl;
std::cout << cost << std::endl;
        //std::cout << "sum: " << sum << std::endl;
        //std::cout << sum<< std::endl;
    }
 
}