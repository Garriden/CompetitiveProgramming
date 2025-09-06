//https://codeforces.com/contest/1913/problem/A
// Div. 2
//  *1000

// Swap and Delete

// g++ -o b b.cpp

// strings

// 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    ll max = 0;

    std::cin >> s;

    ll countOnes = 0;
    ll countZeros = 0;
    n = s.size();
    for(int ii = 0; ii < n; ++ii) {
        if(s[ii] == '1') {
            ++countOnes;
        } else {
            ++countZeros;
        }
    }

    int index = 0;

    if(countOnes == countZeros) {
        std::cout << max << std::endl;
        return;
    } else {
        
        while(index < n && countOnes > 0 && countZeros > 0) {
            if(s[index++] == '0') {
                --countOnes;
            } else {
                --countZeros;
            }
        }

        while(index < n && countZeros > 0 && s[index] == '1') {
            --countZeros;
            ++index;
        }

        while(index < n && countOnes > 0 && s[index] == '0') {
            --countOnes;
            ++index;
        }

    }

    std::cout << n - index << std::endl;
    //std::cout << "leaves: " << (leaves + 1)  / 2 << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
