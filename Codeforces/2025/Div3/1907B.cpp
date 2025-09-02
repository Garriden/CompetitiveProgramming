// https://codeforces.com/contest/1907/problem/B
// Div. 3
// *1000

// YetnotherrokenKeoard

// g++ -o b b.cpp

// data structures
// implementation
// strings

// Two stacks, lowercase and uppercase, to track the indexes. 

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
    std::cin >> s;

    std::stack<ll> lowercaseIndexes;
    std::stack<ll> uppercaseIndexes;
    
    for(ll ii = 0; ii < s.size(); ++ii) {
        char c = s[ii];
        if(c == 'b') {
            // find last lowercase and erase it.
            if(!lowercaseIndexes.empty()) {
                s[lowercaseIndexes.top()] = '0'; // substitute.
                lowercaseIndexes.pop();
            }
        } else if(c == 'B') {
            if(!uppercaseIndexes.empty()) {
                // find last uppercase and erase it.
                s[uppercaseIndexes.top()] = '0'; // substitute.
                uppercaseIndexes.pop();
            }

        } else if(c >= 'a' && c <= 'z') { // lowercase
            lowercaseIndexes.push(ii);

        } else if(c >= 'A' && c <= 'Z') { // uppercase
            uppercaseIndexes.push(ii);

        }

    }

    //for(ll ii = 0; ii < s.size(); ++ii) {
    //    std::cout << s[ii] << " ";
    //} std::cout << std::endl;

    // rebuild string.
    std::string res = "";
    for(ll ii = 0; ii < s.size(); ++ii) {
        if(s[ii] != '0' && s[ii] != 'b' && s[ii] != 'B') {
            res.push_back(s[ii]);
        }
    }

    //std::cout << "attendance: " << attendance << std::endl;
    std::cout << res << std::endl;
    //std::cout << n - attendance << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
