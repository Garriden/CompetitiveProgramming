//https://codeforces.com/contest/2057/problem/A

//g++ -o hola a.cpp

// math trick.

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* pow */
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, m, CA;
    ll a;
    std::cin >> t;
    while(t --> 0) {
        std::cin >> n >> m;

        if(n > m) {
            m = n;
        }

        std::cout << m+1 << std::endl;
    }

}
