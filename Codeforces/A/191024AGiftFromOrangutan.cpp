#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
//g++ -o hola hola.cpp
 
int main() {
    ll t, n, CA;
    ll a;
    std::cin >> t;
    while(t--) {
        ll oddNums = 0;
        ll sum = 0;
        ll minim = INT_MAX;
        ll maxim = 0;
        ll maximC = 0;
        ll minimC = 0;
        std::cin >> n;
        ll N = n;

        std::vector<int> va;

        while(n>0) {
            std::cin >> a;

            if(a > maxim) {
                maxim = a;
                maximC = 1;
            } else if( a == maxim) {
                maximC++;
            }



            if(a < minim) {
                minim = a;
                minimC = 1;
            } else if(( a == minim)) {
                minimC++;
            }

            va.push_back(a);
            //v.erase 
            n--;
        }
        //std::vector<int> va1 = va;
        //std::vector<int> va2 = va;
        //std::sort(va1.begin(), va1.end());
        //std::sort(va2.begin(), va2.end(), greater<int>());
/*
        for(int ii = 0; ii < N; ++ii) {
            b[ii] = min(va1[0], va1[ii]);
            c[ii] = max(va2[0], va2[ii]);


            bb[ii] = min(va2[0], va2[ii]);
            cc[ii] = max(va1[0], va1[ii]);
            //sum += aux2-aux1;
        }
     
        for(int ii = 0; ii < N; ++ii) {
            cout << b[ii] << " ";
        }
        cout << endl;

                for(int ii = 0; ii < N; ++ii) {
            cout << bb[ii] << " ";
        }
        cout << endl;

        for(int ii = 0; ii < N; ++ii) {
            cout << c[ii] << " ";
        }
        cout << endl;
        for(int ii = 0; ii < N; ++ii) {
            cout << cc[ii] << " ";
        }
        cout << endl;
*/
        //sum = maxim;
        for(int ii = 1; ii < N; ++ii) {
            sum += (maxim-minim);
        }



        //std::cout << "sum: " << sum << std::endl;
        std::cout << sum << std::endl;
    }
 
}