// https://codeforces.com/contest/1914/problem/A
// Div. 3
//  *800

// Problemsolving Log

// g++ -o a a.cpp

// implementation
// strings

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll max = 0;

    std::cin >> n;
    
    std::vector<ll> v(28, 0);
    std::cin >> s;

    for(int ii = 0; ii < s.size(); ++ii) {
        v[s[ii] - 'A']++;
    }

    for(int ii = 0; ii < v.size(); ++ii) {
        if(v[ii] > ii) {
            ++max;
        }
    }

    //std::cout << "max: " << max << std::endl;
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
