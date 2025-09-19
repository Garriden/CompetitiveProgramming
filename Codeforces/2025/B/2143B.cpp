// https://codeforces.com/contest/2143/problem/B
// Div. 2
// 1000
// 47m

// Discounts

// g++ -o b b.cpp

// greedy
// sortings
// two pointers

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;
    ll max = 0;

    std::cin >> n >> k;

    std::vector<ll> va(n);
    std::vector<ll> vb(k);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }
    for(int ii = 0; ii < k; ++ii) {
        std::cin >> vb[ii];
    }

    std::sort(va.begin(), va.end(), std::greater<ll>());
    std::sort(vb.begin(), vb.end());

    ll left = 0;
    ll sum = 0;
    for(int ii = 0; ii < vb.size(); ++ii) {
        ll pickElement = vb[ii] - 1;

        //std::cout << "pickElement: " << pickElement << "  / left: " << left << std::endl;

        if(pickElement + left < va.size()) {
            //sum += va[pickElement + left];
            va.erase(va.begin() + pickElement + left);
        } else {
            break;
        }

        left += pickElement;
    }

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    for(int ii = 0; ii < va.size(); ++ii) {
        sum += va[ii];
    }
    
    //std::cout << "max: " << sum << std::endl;
    std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
