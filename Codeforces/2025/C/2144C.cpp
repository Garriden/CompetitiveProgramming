// https://codeforces.com/contest/2144/problem/C
// Edu Div. 2
// 

// Non-Descending Arrays

// g++ -o c c.cpp

// combinatronics
// dp

// Calculate the number of good subsets (both arrays sorted).
// Chose any subset of indices and swap the elements in those positions.
// AKA: Find all posible combinations.

// This problem can be effectively solved using dynamic programming (DP).
//  The core idea is to build the solution from the ground up, making decisions for each
//  pair of numbers and storing the results to avoid redundant calculations.
// Time complexity: O(N) instead of O(N^2)

// To calculate all possible combinations in a dynamic programming problem,
//  you sum the previous states because you're using a counting DP approach.
//  Each state in a counting DP problem represents a number of ways to achieve a subproblem solution.
//  When a subproblem can be reached from multiple valid previous states, 
//  you must add the counts from all of those states to find the total number of ways
//  to reach the current state.

// Both states are necessary, swapped and unswapped.

// We can optimize the SPACE complexity from O(N) to O(1) by only keeping track of 
//  the previous dp states, since the calculation for index i only depends on i-1.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long


bool isSortedNonDecreasing(const std::vector<ll> &v)
{
    for(int ii = 1; ii < v.size(); ++ii) {
        if(v[ii] >= v[ii-1]) {
            // Cool.
        } else {
            return false;
        }
    }

    return true;
}



void solve2()
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
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
    }

    // dp[0] represents ways where va[i-1] is smaller
    // dp[1] represents ways where va[i-1] is larger
    ll dpPrevSmaller = 0;
    ll dpPrevLarger = 0;

    dpPrevSmaller = 1;
    dpPrevLarger = 1;

    for(int ii = 1; ii < n; ++ii) {
        ll dpCurrentSmaller = 0;
        ll dpCurrentLarger = 0;

        // Case for dp[ii][0] (current smaller element is va[ii]).
        // Came from a state where va[ii - 1] was smaller.
        if(va[ii - 1] <= va[ii] && vb[ii - 1] <= vb[ii]) {
            dpCurrentSmaller = (dpCurrentSmaller + dpPrevSmaller) % modulo;
            dpCurrentLarger = (dpCurrentLarger + dpPrevLarger) % modulo;
        }
        // Came from a state where va[i-1] was larger.
        if(va[ii - 1] <= vb[ii] && vb[ii - 1] <= va[ii]) { // Like a swap.
            dpCurrentSmaller = (dpCurrentSmaller + dpPrevLarger) % modulo;
            dpCurrentLarger = (dpCurrentLarger + dpPrevSmaller) % modulo;
        }

        dpPrevSmaller = dpCurrentSmaller;
        dpPrevLarger = dpCurrentLarger;
    }

    std::cout << (dpPrevLarger + dpPrevSmaller) % modulo << std::endl;
}


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
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> vb[ii];
    }

    if(isSortedNonDecreasing(va) && isSortedNonDecreasing(vb)) {
        ++max;
    }


/*
    std::vector<std::vector<ll> > vCombinations;

    for(ll ii = 0; ii < n; ++ii) {
        vCombinations.push_back({va[ii], vb[ii]});
    }


    std::vector<std::vector<std::vector<ll> > > all_combinations;
    std::vector<std::vector<ll> > current_combination;

generate_combinations(vCombinations, all_combinations, current_combination, 0);


    // Print all combinations.
    std::cout << "All combinations of indexed pairs:" << std::endl;
    for(const auto& combo : all_combinations) {
        std::cout << "{";
        for(const auto& pair : combo) {
            std::cout << "{" << pair[0] << ", " << pair[1] << "}";
            //std::is_sorted(vb.begin(), vb.end(), std::less_equal<ll>())

        }
        std::cout << "}" << std::endl;
    }

*/
    //for(int ii = 0; ii < n; ++ii) {
    //    std:: cout << va[ii] << " ";
    //} std::cout << std::endl;
    //std::cout << " l: " << l <<  "  / r: " << r << std::endl;

    //std::accumulate(vb.begin(), vb.end(), max);

    //std::cout << "max: " << max << std::endl;
    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve2();
    }

}
