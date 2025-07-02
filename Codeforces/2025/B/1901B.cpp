//https://codeforces.com/contest/1901/problem/B
// Div. 2
//   *1100

// Chip and Ribbon

// g++ -o b b.cpp

// greedy
// math
// two pointers

// Not working in O(n^2)
// Just a iteration O(n)
// if current > before

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;

    std::vector<ll> va(n, 0);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }


    ll before = 0;
    ll cont = 0;

    for(int ii = 0; ii < n; ++ii) {
        if(va[ii] > before) {
            cont += va[ii] - before;
        }

        before = va[ii];
    }

    //std::cout << "cont: " << cont << std::endl;
    std::cout << cont - 1 << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
