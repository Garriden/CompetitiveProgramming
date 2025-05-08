// Coin Games
//https://codeforces.com/contest/1972/problem/B
// Div. 2
// 750
// 20min

//g++ -o a a.cpp

// Games

// Do a lot of examples.
// In this case, just check the parity of the Upper coins.

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
        std::string s;
        cin >> s;

        int count = 0;
        for(int ii = 0; ii < s.size(); ++ii) {
            if(s[ii] == 'U') {
                ++count;
            }
        }

        if(count % 2 == 1) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO"  << std::endl;
        }

    }
    return 0;
}