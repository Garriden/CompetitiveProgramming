//https://codeforces.com/contest/2057/problem/B

//g++ -o hola a.cpp

// Still slow! But I think Otime is the same!

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
//    Math trick: Note that f(a) is the number of distinct numbers in the array.
//    So just the step 2 is important.

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
        vector<int> va(n);
        map<int, int> m;

        for(int ii = 0; ii < n; ++ii) {
            cin >> a;
            va[ii] = a;
            m[a]++;
        }

        //////
        // 2. How many conversions could I do? Objective: Accomplish most repeated numbers.
        //      a map? key=number, value=repetitions, and order it by the number of repetitions?
        //////

        std::vector<std::pair<int, int> > vAux; // number of repetitions, key(original value)
        for (auto it = m.begin(); it != m.end(); ++it) {
            vAux.push_back({it->second, it->first});
        }

        // sort vector by first value. So numbers with less repetitions can change into already repeated numbers.
        std::sort(vAux.begin(), vAux.end(), [](const auto& left, const auto& right) {
            return left.first < right.first;
        });

        //std::cout << "Sorted by first value (using function):\n";
        //for (const auto& p : vAux) {
        //    std::cout << "(" << p.first << ", " << p.second << ") ";
        //}
        //std::cout << std::endl;

        for(int ii = 0; (ii < vAux.size()) && (k > 0); ++ii) {
            if(vAux[ii].first <= k) {
                k -= vAux[ii].first;
                vAux.erase(vAux.begin() + ii);
                --ii;
            } else {
                break;
            }
        }

        //std::cout << "Final vAux:\n";
        //for (const auto& p : vAux) {
        //    std::cout << "(" << p.first << ", " << p.second << ") ";
        //}
        //std::cout << std::endl;

        int res = vAux.size();
        if(res == 0) {
            res = 1;
        }
        std::cout << res << std::endl;
    }

}
