// https://codeforces.com/contest/2140/problem/C
// Div. 2
// 1250

// WA

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;

    std::cin >> n;

    std::vector<ll> va(n);
    std::vector<ll> negs;
    std::vector<ll> posis;

    ll cost = 0;
    ll sum = 0;
    ll minPosi = LONG_LONG_MAX;
    ll indexMin = 0;
    ll maxNeg = 0;
    ll indexMax = 0;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        if(ii%2 == 0) {
            sum += va[ii];
            posis.push_back(va[ii]);
            if(va[ii] < minPosi) {
                minPosi = va[ii];
                indexMin = ii;
            }
        } else {
            sum -= va[ii];
            negs.push_back(va[ii]);
            if(va[ii] >= maxNeg) {
                maxNeg = va[ii];
                indexMax = ii;
            }
        }

    }

    //std::cout << "sum: " << sum << "  / minPosi: " << minPosi << "  / maxNeg: " << maxNeg << std::endl;
    //std::cout << "indexMin: " << indexMin << "  / indexMax: " << indexMax << std::endl;

    if(maxNeg > minPosi) {
        //std::cout << "a" << std::endl;
        sum += maxNeg*2;
        sum -= minPosi*2;
        sum += (indexMax - indexMin);
    } else if(maxNeg == minPosi) {
        //std::cout << "b" << std::endl;
        sum += (n - 1);
    } else {
        if(negs.size() > 1) {
            sum += ((negs.size() - 1) * 2);
        }
    }

    //std::cout << "sum: " << sum << std::endl;
    std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
