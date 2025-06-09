//https://codeforces.com/contest/2117/problem/A
// Div. 3
// 

// False Alarm

// g++ -o a a.cpp

// greedy
// implementation

// Just iterate greedy

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n >> x;

    int min = INT_MAX;
    int max = 0;
    bool firstFound = false;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> a;
        if(a == 1) {
            if(!firstFound) {
                min = ii;
                firstFound = true;
            }

            max = ii;
        }
    }

    //std::cout << "max-min: " << max-min << std::endl;
    if(max-min < x) {
        std::cout << "YEs" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << cont << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
