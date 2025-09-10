// https://codeforces.com/contest/2140/problem/A
// Div. 2
// 500

// Shift Sort

// g++ -o a a.cpp

// strings

// Count the number of zeros of the string.
// Resultant vector should be "000...111".
// Iterate from the first position to the zeroCount.
// Update resultCount if you find a '1', because that one should be swapped with a zero not yet found.

// Simply sort the string and compare with the original one.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    int max = 0;

    std::cin >> n >> s;

    int zerosBeforeOnes = 0;
    int onesAfterZeros = 0;
    int zeros = 0;
    int ones = 0;
    bool ordered = true;
    for(int ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == '0' && ones == 0) {
            ++zerosBeforeOnes;
        } else if(s[ii] == '1' && zeros == 0) {
            ++onesAfterZeros;
        }


        if(s[ii] == '0') ++zeros;
        else ++ones;


        if(ones > 0 && s[ii] == '0') {
            ordered = false;
        }
    }

    int swaps = 0;
    for(int ii = 0; ii < zeros; ++ii) {
        if(s[ii] == '1') {
            ++swaps;
        }
    }

    //std::cout << "zerosBeforeOnes: " << zerosBeforeOnes << std::endl;
    //std::cout << "onesAfterZeros: " << onesAfterZeros << std::endl;
    if(ordered) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << swaps << std::endl;
    }


    //std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
