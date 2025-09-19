// https://codeforces.com/contest/2143/problem/A
// Div. 2
// 500
// 18m

// All Lengths Subtraction

// g++ -o a a.cpp

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

    std::cin >> n;

    std::vector<ll> va(n);
    std::vector<ll> vb(n);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }

    k = 1;
    int K = 1;
    int N = n;
    bool nextMustBeN = false;

    while(K <= N) {
        // find n.
        for(int ii = 0; k > 0 && ii < N; ++ii) {
            if(va[ii] == n) {
                --va[ii];
                --k;
                nextMustBeN = true;
                //std::cout << "nextMustBeN : true   / k: " << k << std::endl;
            } else {
                //nextMustBeN = false;
                if(nextMustBeN && k < K && k > 0) {
                    break;
                }
            }
        }

        if(nextMustBeN && k > 0) {
            std::cout << "No" << std::endl;
            return;
        }

        nextMustBeN = false;
        
        --n;

        ++K;
        k = K;
    }


    for(int ii = 0; ii < n; ++ii) {
        if(va[ii] != 0) {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    std::cout << "YES" << std::endl;
    
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
