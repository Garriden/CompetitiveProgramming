// https://codeforces.com/contest/2144/problem/A
// Edu Div. 2
// 

// Cut the Array

// g++ -o a a.cpp

// math
// number theory
// bruteforce

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

    std::vector<ll> va(n);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        va[ii] = va[ii] % 3;
    }

    l = 0;
    r = l + 1;
    ll L = l;
    ll R = r;

    ll s1 = 0;
    ll s2 = 0;
    ll s3 = 0;
    while(l < n - 2) {

        while(r < n - 1) {
            for(int ii = 0; ii <= l; ++ii) {
                s1 += va[ii];
            }
            for(int ii = l + 1; ii <= r; ++ii) {
                s2 += va[ii];
            }
            for(int ii = r + 1; ii < n; ++ii) {
                s3 += va[ii];
            }
            s1 = s1 % 3;
            s2 = s2 % 3;
            s3 = s3 % 3;

            if(s1 == s2 && s1 == s3) {
                std::cout << l+1 << " " << r+1 << std::endl;
                return;
            } else if(s1 != s2 && s1 != s3 && s2 != s3) {
                std::cout << l+1 << " " << r+1 << std::endl;
                return;
            }

            s1 = 0;
            s2 = 0;
            s3 = 0;

            ++r;
        }

        ++l;
        r = l + 1;
    }

    //std::cout << "max: " << max << std::endl;
    //std::cout << "(2023.0 / max): " << (2023.0 / max) << std::endl;

    //std::accumulate(vb.begin(), vb.end(), max);


    //std::cout << "max: " << max << std::endl;
    std::cout << 0 << " " << 0 << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
