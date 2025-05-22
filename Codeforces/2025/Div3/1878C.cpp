// https://codeforces.com/contest/1878/problem/C
// Div. 3
// 900 ?

// Vasilije in Cacak

// g++ -o c c.cpp

// math

// Check the minimum and maximum sum possible.
// Formula: Make pairs: 1 + k = k+1, 2 + k-1 = k+1. So we have (k+1), k/2 times.

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, CA;
    ll a, k, x;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> k >> x;

        // Formula: Make pairs: 1 + k = k+1, 2 + k-1 = k+1. So we have (k+1), k/2 times.
        ll minSum = k * (k + 1LL) / 2LL;
        //ll maxSum = k * (2LL * n + 1LL - k) / 2LL;
        ll maxSum = (n * (n + 1LL) / 2LL) - ((n - k) * (n - k + 1LL) / 2LL);

/* BF:
            for(ll ii = 0; ii < k; ++ii) {
                maxSum += (n - ii);
            }

            for(ll ii = 0; ii < k; ++ii) {
                minSum += (ii + 1);
            }
*/
        //std::cout << "minsum: " << minSum << " / maxsum: " << maxSum <<  "  / x: " << x << std::endl;
        if(x >= minSum && x <= maxSum) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

    }

}
