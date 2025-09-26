// https://codeforces.com/contest/2149/problem/C
// Div. 3
//
// 27 min

// MEX rose

// g++ -o c c.cpp

// greedy

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, m, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;
    ll max = 0;
    ll min = INT_MAX;

    std::cin >> n >> k;
    ll N = n;

    //std::vector<std::set<ll> > v(m);
    std::vector<ll> v(n, 0);
    std::vector<bool> toFill(n, false);

    ll KAS = 0;
    ll majorKAS = 0;
    ll minorKASRepeated = 0;
    ll index = 0;
    while(n --> 0) {
        std::cin >> v[index];

        if(v[index] < k && toFill[v[index]]) {
            ++minorKASRepeated;
        }

        toFill[v[index]] = true;
        if(v[index] == k) {
            ++KAS;
        } else if(v[index] > k) {
            ++majorKAS;
        }

        ++index;
    }

    ll sum = 0;
    for(int ii = 0; ii < N && ii < k; ++ii) {
        if(!toFill[ii]) {
            ++sum;
            if(KAS > 0) {
                --KAS;
            } else if(minorKASRepeated > 0) {
                --minorKASRepeated;
            } else if(majorKAS > 0) {
                --majorKAS;
            }

        }
    }

    while(KAS --> 0) {
        ++sum;
    }

    //if(max == 3 && min == 1 && m == 2) {
    //    std::cout << "No" << std::endl;
    //    return;
    //}
    //if(min == 0) {
    //    std::cout << "nO" << std::endl;
    //    return;
    //}

    std::cout << sum << std::endl;
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
