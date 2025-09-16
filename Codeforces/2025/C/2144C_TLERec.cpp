// https://codeforces.com/contest/2144/problem/C
// Edu Div. 2
// 

// Non-Descending Arrays

// g++ -o c c.cpp

// combinatronics
// dp

// TLE
// Recursion with backtracking.

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



void Recc(std::vector<ll>& va, std::vector<ll>& vb, int index, 
    std::vector<bool>& swaps, std::set<std::vector<bool> > &coms)
{
    
    if(va.size() == index)
    {
        if(isSortedNonDecreasing(va) && isSortedNonDecreasing(vb))
        {
            coms.insert(swaps);
        }
        return;
    }



    swaps[index] = false;
    Recc(va, vb, index + 1, swaps, coms);
    
    std::swap(va[index], vb[index]);
    swaps[index] = true;
    Recc(va, vb, index + 1, swaps, coms);

    // backtrack.
    std::swap(va[index], vb[index]);
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

    std::vector<bool> swaps(n);
    std::set<std::vector<bool> > combs;
    Recc(va, vb, 0, swaps, combs);
    std::cout << combs.size() << std::endl;

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
        solve();
    }

}
