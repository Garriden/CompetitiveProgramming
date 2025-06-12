//https://codeforces.com/contest/1891/problem/B
// Div. 2
// 2

// Deja Vu

// NOT WORKING - TE

// g++ -o b b.cpp

// brute force
// math
// sortings

// Note that xi (1≤xi≤30) is a positive integer not exceeding 30.
// Time will be O(30*n)

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, k;
    ll a, b, p, q;
    std::string s, t;
    std::cin >> n;
    std::cin >> q;

    std::vector<ll> va(n);
    std::vector<ll> vx(q);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
    }
    for(int ii = 0; ii < q; ++ii) {
        std::cin >> vx[ii];
    }

    std::vector<ll> memoExponentials(q, 0);
    std::vector<ll> memoExponentialsImpostor(q, 0);
    std::vector<int> evenIndexes;
    for(int ii = 0; ii < n; ++ii) {
        if(va[ii] % 2 == 0) {
            evenIndexes.push_back(ii);
        }
    }

    for(int ii = 0; ii < q; ++ii) {
        for(int jj = 0; jj < evenIndexes.size(); ++jj) {
            if(memoExponentials[ii] == 0) {
                memoExponentials[ii] = static_cast<ll>(std::exp2(vx[ii]));
                memoExponentialsImpostor[ii] = static_cast<ll>(std::exp2(vx[ii] - 1));
            }

            if( (va[evenIndexes[jj]] %  memoExponentials[ii]) == 0 ) { // divisible by 2^xi
                va[evenIndexes[jj]] += (memoExponentialsImpostor[ii]);
            }

        }
    }


    for(int ii = 0; ii < n; ++ii) {
        std::cout << va[ii] << " ";
    } std::cout << std::endl;

    //std::cout << "contPartitions: " << contPartitions << std::endl;
    //std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
