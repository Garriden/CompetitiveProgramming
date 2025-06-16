//https://codeforces.com/contest/1899/problem/C
// Div. 3
// *1100

// Yarik and Array

// g++ -o c c.cpp

// dp
// greedy
// two pointers

// Classical algorithm with keeping minimal prefix sum on the prefix.
// max = sum - minPrefixSum;
// This means thT IF SOME SUBSEQUENCE OF NEGATIVE NUMBERS MAKE OUR MAX LOWER, ups.
//  Will shorten this subsequence until the values are again positive.

// Not enough tests.

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
    ll minPrefixSum = 0;
    std::vector<ll> va(n);
    //std::vector<ll> vMaxAccumulated(n);

    
    std::cin >> va[0];
    ll before = va[0];
    sum += va[0];
    //vMaxAccumulated[0] = sum;
    if(va[0] > max) {
        max = va[0];
    }
    if(va[0] < minPrefixSum) {
        minPrefixSum = va[0];
    }

    for(int ii = 1; ii < n; ++ii) {
        std::cin >> va[ii];


        if(std::abs(before % 2) == std::abs(va[ii] % 2)) {
            // The alternating sequence is broken. You cannot extend the current subarray.
            // Therefore, you must start a new potential alternating subarray sequence.
            sum = va[ii];
            minPrefixSum = 0;
        } else { // different parity.
            sum += va[ii];
        }

        //vMaxAccumulated[ii] = sum;

        if((sum - minPrefixSum) > max) {
            // sum is the current prefix sum of the alternating sequence ending at va[ii].
            // minPrefixSum is the minimum prefix sum encountered so far within this alternating sequence.
            
            // By subtracting the min prefix sum from the sum,  you effectively get the sum of the subarray 
            //  that starts right after the point where min was recorded, and ends at va[ii].
            
            max = sum - minPrefixSum;
        }

        // It stores the smallest sum encountered up to the current element included within the current sequence.
        if(sum < minPrefixSum) {
            minPrefixSum = sum;
        }

        before = va[ii];
    }


/*
    ll left = 0;
    //std::cout << " maxAcc: ";
    for(int ii = 0; ii < n; ++ii) {
        if(vMaxAccumulated[ii] > max) {
            left = ii - 1;
            max = vMaxAccumulated[ii];

            // see if can remove negative numbers on the left
            ll maxImpostor = max;
            while(left > 0) {
                maxImpostor -= va[left];
                //std::cout << " maxImpostor: " << maxImpostor << std::endl;
                if(maxImpostor > max) {
                    max = maxImpostor;
                }
                --left;
            }
        }
        //std::cout << vMaxAccumulated[ii] << " ";
    } //std::cout << std::endl;
*/
    
    //std::cout << " max: " << max << std::endl;
    std::cout << max << std::endl;
    
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
