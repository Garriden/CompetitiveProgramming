//https://codeforces.com/contest/1913/problem/A
// Div. 2
//  *800

// Rating Increase

// g++ -o a a.cpp

// implementation

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

    --n;

    for(int ii = 1; ii < s.size(); ++ii) {
        std::string s1 = s.substr(0, ii);
        std::string s2 = s.substr(ii, s.size() - ii);
        int n1 = std::stoi(s1);
        if(s2 != "") {
            int n2 = std::stoi(s2);
            if( (s1[0] != '0' && s2[0] != '0') && (n1 > 0 && n2 > 0) && n2 > n1 ) {
                std::cout << s1 << " " << s2 << std::endl;
                return;
            }
        }
    }

    std::cout << -1 << std::endl;

    //std::cout << "leaves: " << (leaves + 1)  / 2 << std::endl;
    //std::cout << (leaves + 1)  / 2 << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
