// https://codeforces.com/contest/2149/problem/D
// Div. 3
//

// A and B

// g++ -o d d.cpp

// strings

// What if two bigger blocks ?

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n;
    std::string s;
    std::cin >> n;
    std::cin >> s;

    if(n <= 3) {
        std::cout << 0 << std::endl;
        return;
    }

    ll middle = n/2;

    std::vector<ll> va;
    std::vector<ll> vb;
    for(ll ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == 'a') {
            va.push_back(ii);
        } else if(s[ii] == 'b') {
            vb.push_back(ii);
        }
    }
    ll retA = 0;
    ll retB = 0;

    for(ll ii = 0; ii < va.size(); ++ii) {
        //std::cout << va[ii] << " ";
        retA += (std::abs(va[middle-1] - va[ii] - 1) - std::abs(middle-1 - ii));
        //std::cout << std::abs(va[middle] - va[ii]) - std::abs(middle - ii) << "  / ";
    }//std::cout << std::endl;

    for(ll ii = 0; ii < vb.size(); ++ii) {
        //std::cout << vb[ii] << " ";
        retB += (std::abs(vb[middle-1] - vb[ii] - 1) - std::abs(middle-1 - ii));
        //std::cout << std::abs(vb[middle] - vb[ii]) - std::abs(middle - ii) << "  / ";
    }//std::cout << std::endl;

    //std::cout << "retB: " << retB << "  retA:" << retA << std::endl;
    ll ret = std::min(retB, retA);
    std::cout << ret << std::endl;
    //std::cout << "max: " << max << std::endl;
    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
