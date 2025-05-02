//https://codeforces.com/contest/2108/problem/A
// Div. 2

//g++ -o a a.cpp

// Combunatorics
// Number theory
// Math
// Greedy
// Memorization

// Math thick:
//  Just calculate even numbers from 0 to maximum permutation (decreasing order).

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#define ll unsigned long long
using namespace std;

/* 
// Memorization ? Don't need.
int calc(int n) {
    if(n == 1) {
    return 1;
    } else if(n == 2) {
    return 2;
    } else if (n >= 3) {
        int sum = 0;
        for(int ii = 1; ii <= n-2; ++ii) {
            sum += std::ceil(static_cast<double>(ii + 1) / 2.0);
        }
        return 2 + sum;
    } else {
        return -1;
    }
}
*/

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        double na;
        std::cin >> na;

        // n^2/4 +1
        std::cout << (int)((na*na)/4 + 1) << std::endl;
    }

}