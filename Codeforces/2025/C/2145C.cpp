// https://codeforces.com/contest/2145/problem/C
// Educational Codeforces Round.
//   *1300
// WA

// Monocarp's String

// g++ -o c c.cpp

// greedy
// strings

// Ah, when he says consecutive letters, could it be consecutive 'a' and 'b' !

// "Minimum Substring Removal to Balance 'a' and 'b' Counts".
//  It uses the prefix sum and hash map technique to find the shortest substring to remove.

// The secret is: we need to find a piece to remove that has 
//  an imbalance that perfectly cancels out the total imbalance of the whole necklace.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<ll> v(n + 1, 0);
    ll as = 0;
    ll bs = 0;
    ll aConsec = 0;
    ll bConsec = 0;
    ll aConsecMax = 0;
    ll bConsecMax = 0;

    for(int ii = 1; ii <= n; ++ii) {
        if(s[ii - 1] == 'a') {
            v[ii] = v[ii - 1] + 1;
        } else if(s[ii - 1] == 'b') {
            v[ii] = v[ii - 1] - 1;
        }
        //std::cout << v[ii] << " ";
    } //std::cout << std::endl;

    ll ret = 0;

    if(v[n] == 0) {
        std::cout << 0 << std::endl;
        return;
    } else {
        std::unordered_map<ll, ll> mp;
        mp[0] = 0;

        ll left = n;
        for(ll ii = 1; ii <= n; ++ii) {
            ll target = v[ii] - v[n];
            if(mp.count(target)) {
                ll i_pos = mp[target];
                ll len = ii - i_pos;
                if(len < left) {
                    left = len;
                }
            }

            mp[v[ii]] = ii;
        }

        if(left == n) {
            ret = -1;
        } else {
            ret = left;
        }

    }

    std::cout << ret << std::endl;

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "max: " << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
