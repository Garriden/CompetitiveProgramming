// https://codeforces.com/contest/2173/problem/A
// Codeforces Round 1068 (Div. 2)
//  105

// Sleeping Through Classes

// g++ -o a a.cpp

// implementation

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

    //std::cin >> n;

    //std::vector<ll> va(n);
    //std::vector<ll> vb(n);
    //std::set<ll> set;
    ll min = 0;
    ll max = INT_MAX;
    std::cin >> n >> k;
    std::cin >> s;

    ll sise = s.size();
    ll res = 0;
    int cont = -1;
    for(int ii = 0; ii < sise; ++ii) {

        if(s[ii] == '1') {
            cont = k;
        } else { // can sleep ?
            --cont;

            if(cont < 0) {
                cont = -1;
                ++res;
            }
        }

    }
    
    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "max: " << max << "  / min: " << min << "  /  restar: " << restar << std::endl;
    //std::cout << "res: " << res << std::endl;
    std::cout << res << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
