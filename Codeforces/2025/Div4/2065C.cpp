//https://codeforces.com/contest/2065/problem/C1

//g++ -o c c.cpp

// Skibidus and Fanum Tax (easy version)
// Iterate and check vector. Watchout first index.
//  Keep values at minimum.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
//#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void solve()
{
    int t, n, m;
    int a, b;
    std::cin >> n >> m;

    vector<int> va(n);
    vector<int> vb(m);
    for(int ii = 0; ii < n; ++ii) {
        cin >> va[ii];
    }
    for(int ii = 0; ii < 1; ++ii) {
        cin >> vb[ii];
    }
    b = vb[0];

    int last = min(va[0], b - va[0]);

    for(int ii = 1; ii < n; ++ii) {
        va[ii] = min(va[ii], b - va[ii]);

        if(va[ii] < last) {
            va[ii] = b-va[ii];
        } 
        
        if(va[ii] < last) {
            std::cout << "NO" << std::endl;
            return;
        }

        last = va[ii];
    }

    std::cout << "YES" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while(t--) solve();

}