// https://codeforces.com/contest/1878/problem/D
// Div. 3
// 1600 ?

// Reverse Madness

// g++ -o c c.cpp

// data structures
// greedy

/*
BF: for each x, iterate through vector l. O(n)
Binary Search: for each x, search in vector l. O(n*log(n)). Needs to search, still ineficient.

BCR: Make an auxiliar cont vector when reoding x. Q(n) ish...
It keeps track of how many times a swap operation is requested.
Then, iterate l vector, if this value is in cont (and their counterpart), swap.
Compare value on l, with the should have value x.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long

int main() {
    ll t, n, q, min, max;
    ll a, k, x;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> k >> n;
        std::cin >> s;

        std::vector<int> l(n);
        std::vector<int> r(n);

        for(int ii = 0; ii < n; ++ii) {
            std::cin >> l[ii];
        }

        for(int ii = 0; ii < n; ++ii) {
            std::cin >> r[ii];
        }

        std::cin >> q;
        std::vector<int> cont(k, 0);

        for(int ii = 0; ii < q; ++ii) { // cont reverse requests.
            int x;
            std::cin >> x;
            ++cont[x - 1];
        }

        //std::cout << "cont: ";
        //for(int ii = 0; ii < k; ++ii) {
        //    std::cout << cont[ii] << " ";
        //}std::cout << std::endl;

        
        for(int ii = 0; ii < n; ++ii) { // reverse string.
            int lvalue = l[ii] - 1;
            int rvalue = r[ii] - 1;
            //std::cout << "lvalue: " << lvalue << " / rvalue: " << rvalue << std::endl;

            // swap substring.
            //std::cout << "out before: " << s << std::endl;
            ll sum = 0;
            for(ll jj = lvalue ; jj <= (lvalue + rvalue) / 2; ++jj) {
                sum += cont[jj] + cont[rvalue + lvalue - jj];
                if(sum % 2 != 0) {
                    std::swap(s[jj], s[rvalue + lvalue - jj]);
                }
            }
            //std::cout << "out after: " << s << std::endl;
        }

        std::cout << s << std::endl;

    }

}
