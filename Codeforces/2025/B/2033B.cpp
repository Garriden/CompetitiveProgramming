//https://codeforces.com/contest/2033/problem/B
// Recorrer matrzes por dagonales.
// No entena que sumava tota la dagonal sencera. Jo ho fea elementa a element.

//g++ -o hola hola.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* pow */
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA;
    ll a;
    std::cin >> t;
    while(t--) {
        ll sum = 0;
        std::cin >> n;
        ll N = n;
        std::vector<std::vector<int> > mat(n, vector<int>(n));
        std::vector<int> dagonals(2*n, 0);
        int dagCount = 0;
                   
        for(int ii = 0; ii < n; ++ii) {
            for(int jj = 0; jj < n; ++jj) {
                std::cin >> a;
                mat[ii][jj] = a;
            }
        }

        for(int ii = n-1; ii >= 0; --ii) {
            int mn = 0;
            for(int jj = 0; (jj < n) && (ii+jj < n) ; ++jj) {

                int x = mat[jj][ii+jj];
                //std::cout << x << " ";
                if(x < mn) {
                  mn = x;
                }
            }
            dagonals[dagCount] = mn;
            dagCount++;
            //std::cout << std::endl;
        }
//std::cout << "hola" << std::endl;

        for(int ii = n-1; ii >= 1; --ii) {
            int mn = 0;
            for(int jj = 0; (jj < n) && (ii+jj < n) ; ++jj) {

                int x = mat[ii+jj][jj];
                //std::cout << x << " ";
                if(x < mn) {
                  mn = x;
                }
            }
            dagonals[dagCount] = mn;
            dagCount++;
            //std::cout << std::endl;
        }

        int res = 0;
        for(int ii = 0; ii < 2*n; ++ii) {
            res += dagonals[ii];
                //std::cout << dagonals[ii] << " ";
        }

        //    cout << endl;
        //if( unhappy > N/2) {
        //    std::cout << "yes" << std::endl;
        //} else  {
        //    std::cout << "no" << std::endl;
        //}
        //std::cout << sum << std::endl;

        //for(int ii = 0; ii < n; ++ii) {
        //    for(int jj = 0; jj < n; ++jj) {
        //        std::cout << mat[ii][jj] << " ";
        //    }
        //    std::cout << std::endl;
        //}

        std::cout << -1*res << std::endl;
    }

}