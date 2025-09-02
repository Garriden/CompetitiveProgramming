// https://codeforces.com/contest/1907/problem/B
// Div. 3
// *1200

// Removal of Unattractive Pairs

// g++ -o c c.cpp

// constructive
// algorithms
// greedy
// math
// strings

// Even / Odd. Check if the same letter is repeated more than half n.
// My mistake was: Maximum adjacent letters != letter most repeated!
// Instead, use a vector of frequencies.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    ll P, l, t;
    std::string s;
    std::cin >> n >> s;

    // count max adjacent letters.
    std::vector<ll> freq(30, 0);
    for(ll ii = 0; ii < s.size(); ++ii) {
        freq[s[ii] - 'a']++;
    }

    // Count how many times appears the max letter.
    ll repeatedCont = 0;
    for(ll ii = 0; ii < freq.size(); ++ii) {
        if(freq[ii] > repeatedCont) {
            repeatedCont = freq[ii];
        }
    }
    ll nonRepeated = n - repeatedCont;
    //std::cout << "repeatedCont: " << repeatedCont << "  / nonRepeated: " << nonRepeated << std::endl;

    ll ret = (repeatedCont - nonRepeated);
    if(ret < 2) {
        ret = n % 2;
    }

    //std::cout << "ret: " <<  ret << std::endl;
    std::cout << ret << std::endl;
    //std::cout << n << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        /*
        // Watch test failing trick. Wrong answer  Checker comment
        // wrong answer 1683rd numbers differ - expected: '2', found: '0'
        int TOKEN = 1683; // [1683th token]
        int TEST_T_INPUT = 69; // Second test failing, t = 10000
        
        if(t == (TEST_T_INPUT - 1)) {
            std::cout << "AmInTheFailingTest." << std::endl;
            // Now I'm at test 2.
            // I just want the correct token.
            int index = 1;
            while(index++ <= TOKEN) {
                // Simulate the inputs
                ll n;
                std::string s;
                std::cin >> n >> s;

                if(index == (TOKEN - 1)) {
                    std::string out = "n:_" + std::to_string(n) + "_/_s:" + s;
                    std::cout << out << std::endl;
                }
                if(index == (TOKEN)) {
                    std::string out = "n:_" + std::to_string(n) + "_/_s:" + s;
                    std::cout << out << std::endl;
                }

            }
        } else {
            solve();
        }
        */
        solve();
    }

}
