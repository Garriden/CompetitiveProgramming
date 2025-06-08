//https://codeforces.com/contest/1883/problem/A
// Div. 3
// 500  *800

// Morning

// g++ -o a a.cpp

// math
// iterative

// Just iterate.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    //std::cin >> n >> k;
    std::cin >> s;

    int cont = 0;
    int it = 1;
    for(int ii = 0; ii < s.size(); ++ii) {
        bool found = false;
        int value = s[ii] - '0';
        if(s[ii] == '0') {
            value = 10;
        }

        while(!found) {
            if(it == value) {
                found = true;
            } else if(value > it) {
                ++it;
            } else if(value < it) {
                --it;
            }
            ++cont;
        }

    }

    //std::cout << "cont: " << cont << std::endl;
    std::cout << cont << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
