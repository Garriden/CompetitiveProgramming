// https://codeforces.com/contest/2139/problem/B
// Div. 2
// 1000

// Cake Collection

// g++ -o b b.cpp

// sortings
// implementation

// Misleading test cases. Althought I catched teh trick.
// Wrong assumption, ¡ Input WASN'T sorted !
// Check 'a' and 'm'. Watch out when negative.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k, l, r, m;

    std::cin >> n >> m;
    std::vector<ll> va(n);

    for(ll ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    sort(va.begin(), va.end());

    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    ll sum = 0;
    while(n > 0 && m > 0) {
        sum += (va[n - 1] * m);

        --m;
        --n;
    }

    //std::cout << "sum: " << sum << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    std::cout << sum << std::endl;
 
}
 
int main() {
    int t;
    std::cin >> t;
 
    while(t --> 0) {
        solve();
    }
 
}