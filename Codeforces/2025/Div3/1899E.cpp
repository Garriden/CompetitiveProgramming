//https://codeforces.com/contest/1899/problem/E
// Div. 3
//  *1300

// Queue Sort

// g++ -o c c.cpp

// greedy
// implementation
// sortings

// if min first and not ordered: -1
// TE how to convert second for into O(1) ?
// Ah almost, I don't need to sort it (second for), I just can asume it.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p;
    std::string s1;
    std::cin >> n;

    ll sum = 0;
    ll max = LLONG_MIN;
    ll min = LLONG_MAX;
    std::vector<ll> va(n);
    std::vector<ll> vMaxAccumulated(n);

    for(int ii = 0; ii < n; ++ii) {
        std::cin >> va[ii];
        if(va[ii] < min) {
            min = va[ii];
        }
    }

    if(std::is_sorted(va.begin(), va.end())) {
        std::cout << 0 << std::endl;
        return;
    }

    ll cont = 0;
    for(int ii = 0; ii < n; ++ii) {
        ll popedValue = va[ii];
        //std::cout << " popedValue: " << popedValue << " " << std::endl;
        if(std::is_sorted(va.begin() + ii, va.end())) {
            std::cout << cont << std::endl;
            return;
        } else if(popedValue == min) {
            std::cout << -1 << std::endl;
            return;
        }
        
        //va.erase(va.begin()); // pop first element.
        //va.push_back(popedValue);
        ++cont;

        //std::cout << " vec now: ";
        //for(int jj = 0; jj < n; ++jj) {
        //    std::cout << va[jj] << " ";
        //} std::cout << std::endl;

        // shift it to the left
        //for(int k = n - 1; k > 0; --k) {
        //    if(va[k] < va[k-1]) {
        //        std::swap(va[k], va[k-1]);
        //    } else {
        //        break;
        //    }
        //}

        //std::cout << " vec afta: ";
        //for(int jj = 0; jj < n; ++jj) {
        //    std::cout << va[jj] << " ";
        //} std::cout << std::endl;

        //if(std::is_sorted(va.begin(), va.end())) {
        //    std::cout << cont << std::endl;
        //    return;
        //}
    } //std::cout << std::endl;


    //std::cout << cont << std::endl;
    std::cout << cont << std::endl;
    
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
