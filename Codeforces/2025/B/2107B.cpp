//https://codeforces.com/contest/2107/problem/B
// Div. 2
// 750

//g++ -o b bb.cpp

// Games
// Greedy
// Math

// To play optimally, always credrease the maximum.
// Now, the only way to lose, is to have all boxes to 0.
//  !Check the parity!
// Also check the first corner case where Tom cannot do a legal move.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA, k;
    ll a;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;
        std::vector<int> v(n);
        std::cin >> k;

        ll sum = 0;

        for(int ii = 0; ii < n; ++ii) {
            cin >> v[ii];
            sum += v[ii];
        }

        // min at pos 0, max at pos n-1.
        sort(v.begin(), v.end()); // N * log N.
        // Important to do this operation before check, and more important so, reorder the array.
        v[n - 1]--;
        sort(v.begin(), v.end());

        // Check corner case. Game jiggled, doesnt satisfy the formula.
        if((v[n - 1] - v[0]) > k) { // Tom cannot do the first move.
            std::cout << "Jerry" << std::endl;
        } else {
            if(sum % 2 == 1) {
                std::cout << "Tom" << std::endl;
            } else {
                std::cout << "Jerry" << std::endl;
            }
        }

    }

    return 0;
}