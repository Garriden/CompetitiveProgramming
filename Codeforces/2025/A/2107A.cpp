//https://codeforces.com/contest/2107/problem/A
// Div. 2
// 250

//g++ -o a a.cpp

// Greedy
// Number theory
// Math

// Math trick:
//  If all the numbers are the same, print NO.
//   else, put the max on the only subarray because no other gcd would be 
//         bigger than the max.

// C++17: std::gcd in <numeric>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        std::vector<int> v(n);

        cin >> a;
        int before = a;
        int max = a;
        bool no = true;
        v[0] = a;

        for(int ii = 1; ii < n; ++ii) {
            cin >> a;
            if(a != before) { // also could compare min vs max.
                no = false;
            } 

            if(a > max) {
                max = a;
            }

            before = a;
            v[ii] = a;
        }

        if(no) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;

            for(int ii = 0; ii < n; ++ii) {
                if(v[ii] == max) {
                    std::cout << "2 ";
                } else {
                    std::cout << "1 ";
                }
            }
            std::cout << std::endl;
        }

    }
    return 0;
}