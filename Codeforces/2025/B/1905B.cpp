//https://codeforces.com/contest/1905/problem/B
// Div. 2
// 1000 1100

// Begginer's Zelda

// g++ -o b b.cpp

// greedy
// trees

// Count the leaves k. (k+1) / 2

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    ll max = 0;

    std::cin >> n;
    std::vector<ll> neigs(n + 1, 0);
    ll totalNodes = 0;
    ll leaves = 0;

    --n;

    // Build tree (map of neighbours).
    while(n --> 0) {
        std::cin >> a >> b;
        neigs[a-1]++;
        neigs[b-1]++;
    }

    for(int ii = 0; ii < neigs.size(); ++ii) {
        if(neigs[ii] == 1) {
            ++leaves;
        }
    }

    //std::cout << "leaves: " << (leaves + 1)  / 2 << std::endl;
    std::cout << (leaves + 1)  / 2 << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
