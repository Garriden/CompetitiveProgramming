// https://codeforces.com/conte
// Div. 2
// 1500

// A Good Problem

// g++ -o c c.cpp

// bitmasks
// constructive algorithms
// math

// Xor by himself, if the number of times is even, the result is 0.
// Corner case: 6 1 2 4 -> 111122
// The different numbers are just two and not half. Wrong assumption.

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ull n, x, y, k, l, r;
    ull a, b, p;
    std::string s;
    std::cin >> n >> l >> r >> k;
 
    //ll result = (b - a) * x; // first try, just add 1 until reaches next number.
 
    if(r == l && n == 1) {
        std::cout << r << std::endl;
        return;
    } else {
        if(n % 2 == 1) { //odd.
            std::cout << l << std::endl;
            return;
        } else if( n == 2 ) {
            std::cout << -1 << std::endl;
            return;
        } else { // even.
            //std::cout << "even" << std::endl;
 
            //if(n % 4 != 0) {
            //    std::cout << -1 << std::endl;
            //    return;
            //}
 
            // make pairs.
            ull niceL = 1;
            ull niceR = l;
            while(niceL <= r) {
                niceR = niceL;
                //while(niceR <= r) {
                    //std::cout << "niceL: " << niceL << "  / niceR: " << niceR << "  ---   & " << (niceL & niceR) << std::endl;
                    if(niceL > l) {
                        //if((niceL & r) == 0) { // found!
                            // if((niceL & niceR) == (niceL ^ niceR)) { 
                            if(k <= (n - 2) ) {
                                std::cout << l << std::endl;
                                return;
                            } else {
                                std::cout << niceL << std::endl;
                                return;
                            }
                        //}
                    //} else {
 
                    }
                    //++niceR;
                    //std::cout << "niceR: " << niceR << std::endl;
                //}
                //++niceL;
                niceL *= 2;
                //std::cout << "niceL: " << niceL << std::endl;
            }
        }
    }
 
    //for(int ii = 0; ii < n; ++ii) {
    //    std::cout << response[ii];
    //} std::cout << std::endl;
 
    std::cout << -1 << std::endl;
 
    //std::cout << "max: " << max << std::endl;
    //std::cout << "cont: " << cont << std::endl;
    //std::cout << max << std::endl;
 
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
