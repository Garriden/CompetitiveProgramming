//https://codeforces.com/contest/2113/problem/B
// Div. 2
// 750

// Good Start

// g++ -o b b.cpp

// math
// matrix

// Absolute difference in x and y.
// module if it fits x squares.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, x, y, k;
    ll a, b, p, w, h;
    std::string s1;
    std::cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int originDiffX = abs(x1 - x2);
    int originDiffY = abs(y1 - y2);

    //std::cout << "originDiffX: "<< originDiffX << std::endl;
    //std::cout << "originDiffY: "<< originDiffY << std::endl;

    if(originDiffX <= 0 || originDiffY <= 0) { // if same row or column.
        if(originDiffX % a == 0 && originDiffY % b == 0) { // must fit the other axis perfectly.
            std::cout << "YEs" << std::endl;
            return;
            /*
            5 5 2 2
            -1 -1 4 -1
            */
        }
    } else {    // more space between them.
        if(originDiffX % a == 0 || originDiffY % b == 0) { // maybe cannot fit Y, but can fit X.
            std::cout << "Yes" << std::endl;
            return;
            /*
            10 9 3 2
            0 0 6 3
            */
        }
    }


    //std::cout << "  yDiff1: "<< yDiff1 << "  / yDiff2: " << yDiff2 <<  std::endl;
    //std::cout << "  xDiff1: "<< xDiff1 << "  / xDiff2: " << xDiff2 <<  std::endl;


    std::cout << "no" << std::endl;
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
