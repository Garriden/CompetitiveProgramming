//https://codeforces.com/contest/187
// Div. 3
// 4

// Come a Little Closer

// g++ -o d d.cpp

// matrix
// brute force
// greedy
// implementation
// math

//DOESN'T WORK.

// The minimum rectangle that we can choose must have sides of length maxi(xi)−mini(xi)+1
// and maxi(yi)−mini(yi)+1 , meaning that the maximum and minimum values along both axes are important.

// To find the new maximums and minimums, we can use a multiset (No variables, no vetors and less sorting it).
// Do 4 fors, each one removing the min/max/i/j and find the new min or max and calcuate the result.


/*
            // I don't need that
            // Two maxs
            if(a <= minX2) {
                if(a <= minX) {
                    minX2 = minX;
                    minX = a;
                } else {
                    minX2 = a;
                }
            }
            
            if (a >= maxX2) {
                if(a >= maxX) {
                    maxX2 = maxX;
                    maxX = a;
                } else {
                    maxX2 = a;
                }
            }

            if(b <= minY2) {
                if(b <= minY) {
                    minY2 = minY;
                    minY = b;
                } else {
                    minY2 = b;
                }
            }
            
            if (b >= maxY2) {
                if(b >= maxY) {
                    maxY2 = maxY;
                    maxY = b;
                } else {
                    maxY2 = b;
                }
            }
*/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n;

        std::multimap<ll, ll> Mx;
        std::multimap<ll, ll> My; // order ys
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> a >> b;
            Mx.insert({a, b});
            My.insert({b, a});
        }

        //for(auto pair : M) {
        //    std::cout << "x " << pair.first << "  / y: " << pair.second << std::endl;
        //}

        ll maxX = 0;
        ll maxY = 0;
        ll minX = LLONG_MAX;
        ll minY = LLONG_MAX;

        // find mins and maxs.
        for(auto pair : Mx) {
            minX = std::min(minX, pair.first);
            minY = std::min(minY, pair.second);
            maxX = std::max(maxX, pair.first);
            maxY = std::max(maxY, pair.second);
        }


        ll res = (maxX - minX + 1) * (maxY - minY + 1);
        std::cout << res << std::endl;

        // Remove min X.
        auto it = Mx.begin();
        ++it;
        maxX = 0;
        maxY = 0;
        minX = LLONG_MAX;
        minY = LLONG_MAX;
        while(it != Mx.end()) {
            minX = std::min(minX, it->first);
            minY = std::min(minY, it->second);
            maxX = std::max(maxX, it->first);
            maxY = std::max(maxY, it->second);
            ++it;
        }
        res = std::min(res, (maxX - minX + 1) * (maxY - minY + 1));
        std::cout << res << std::endl;

        // remove max X
        it = Mx.end();
        --it;
        maxX = 0;
        maxY = 0;
        minX = LLONG_MAX;
        minY = LLONG_MAX;
        while(it != Mx.begin()) {
            minX = std::min(minX, it->first);
            minY = std::min(minY, it->second);
            maxX = std::max(maxX, it->first);
            maxY = std::max(maxY, it->second);
            --it;
        }
        res = std::min(res, (maxX - minX + 1) * (maxY - minY + 1));
        std::cout << res << std::endl;

        // Remove min Y (reversed).
        it = My.begin();
        ++it;
        maxX = 0;
        maxY = 0;
        minX = LLONG_MAX;
        minY = LLONG_MAX;
        while(it != My.end()) {
            minX = std::min(minY, it->first);
            minY = std::min(minX, it->second);
            maxX = std::max(maxY, it->first);
            maxY = std::max(maxX, it->second);
            ++it;
        }
        res = std::min(res, (maxX - minX + 1) * (maxY - minY + 1));
        std::cout << res << std::endl;

        // Remove max Y (reversed).
        it = My.end();
        --it;
        maxX = 0;
        maxY = 0;
        minX = LLONG_MAX;
        minY = LLONG_MAX;
        while(it != My.begin()) {
            minX = std::min(minY, it->first);
            minY = std::min(minX, it->second);
            maxX = std::max(maxY, it->first);
            maxY = std::max(maxX, it->second);
            --it;
        }
        res = std::min(res, (maxX - minX + 1) * (maxY - minY + 1));
        std::cout << res << std::endl;


        std::cout << "res: " << res << std::endl;

        //std::cout << "sum: " << sum << std::endl;
        //std::cout << sum << std::endl;

    }

}
