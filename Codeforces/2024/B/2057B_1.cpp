//https://codeforces.com/contest/2057/problem/B

// BAD, So slow!

//g++ -o hola a.cpp

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>       /* pow */
#define ll unsigned long long
using namespace std;

// Input 
// 1 11 4
// 3 2 1 4 4 3 4 2 1 3 3
// Output:
// 2

// 1. Find another number (max) but at maximum as the same I am looking right now.
//     reserch? After point 2.

// 2. How many conversions could I do? Objective: Accomplish most repeated numbers.
//      a map? key=number, value=repetitions, and order it by the number of repetitions?

// Agh! so slow!

// --------------------------------
// Solution: Note that f(a) is the number of distinct numbers in the array.

int main() {
    ll t, n, m, CA, a;
    ll p, k;
    std::cin >> t;
    while(t --> 0) {
        std::cin >> n >> k;
        vector<ll> va(n);
        map<ll, int> m;

        for(int ii = 0; ii < n; ++ii) {
            cin >> a;
            va[ii] = a;
            m[a]++;
        }

        //////
        // 2. How many conversions could I do? Objective: Accomplish most repeated numbers.
        //      a map? key=number, value=repetitions, and order it by the number of repetitions?
        //////

        std::vector<std::pair<ll, ll> > vAux; // number of repetitions, key(original value)
        int aa = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            vAux.push_back({it->second, it->first});
        }

        // sort vector by first value.
        std::sort(vAux.begin(), vAux.end(), [](const auto& left, const auto& right) {
            return left.first < right.first;
        });

        //std::cout << "Sorted by first value (using function):\n";
        //for (const auto& p : vAux) {
        //    std::cout << "(" << p.first << ", " << p.second << ") ";
        //}
        //std::cout << std::endl;


        int max = vAux[vAux.size()-1].second;

        for(int ii = 0; (ii < vAux.size()) && (k > 0) && (k); ++ii) {
            int x = 0;
            if(vAux[ii].first <= k) {
                k -= vAux[ii].first;
                x = vAux[ii].second;
                for(int jj = 0; jj < n; ++jj) {
                    if(va[jj] == x) {
                        va[jj] = max;
                    }
                }
            } else {
                break;
            }
        }

        //std::cout << "Vector a after subs: ";
        //for (auto p : va) {
        //    std::cout <<  p << ", ";
        //}
        //std::cout << std::endl;


        //////
        // 1. Find another number (max) but at maximum as the same I am looking right now.
        //     reserch? After point 2.
        //////

        int count = 0;
        vector<bool> found(n, false);

        for(int ii = 0; ii < n; ++ii) {
            if(!found[ii]) {
                int l = va[ii];
                for(int jj = ii+1; jj < n; ++jj) { // find another one equal.
                    if(va[jj] == l) {
                        found[jj] = true;
                    }
                }
                ++count;
            }
        }


        std::cout << count << std::endl;
    }

}
