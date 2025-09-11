// https://codeforces.com/contest/1914/problem/C
// Div. 3
//  *1100

// Quests

// g++ -o c c.cpp

// math
// greedy

// Evaluate the current max, no need for a vector of intermediate maxs.

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
    ll sum = 0;
    ll ret = 0;

    std::cin >> n >> k;
    std::vector<ll> va(n, 0);
    std::vector<ll> vb(n, 0);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
    }

    // first iter.
    //sum += va[it];
    ll it = 0;
    //++it;


    while(it < k && it < n) {
        //if(va[it] == 0 || vb[it] == 0) break;

        //ll expNewB = vb[it - 1];
        ll expNewB = vb[it];
        ll iteracionsRestants = k - it - 1;

        sum += va[it];
        max = std::max(expNewB, max);

        //std::cout << "expNewB: "<< expNewB << " * " << iteracionsRestants << " + " << sum << std::endl;
        //maxTeoricB[it] = expNewB * iteracionsRestants + sum;

        ret = std::max(ret, sum + max * iteracionsRestants);

        ++it;
    }

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << maxTeoricB[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << std::endl;
    std::cout << ret << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
