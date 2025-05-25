//https://codeforces.com/contest/1877/problem/B
// Div. 2
// 1000

// Helmets in Night Light

// g++ -o b b.cpp

// sortings
// greedy

// std: multimap <ll, ll> myMap;
// myMap.insert ({x, y});
// while(!myMap.empty()) { ...
//   auto it = my Map.begin();
//   ll a = it→first;
//   ll b = it→second; 
//   myMap.erase(it);

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, p;
    std::string s;
    std::cin >> t;

    while(t --> 0) {
        std::cin >> n >> p;
        ll sum = 0;
        ll firstPointer = 0;
        ll lastPointer = n - 1;

        std::vector<ll> va(n);
        std::vector<ll> vb(n);
        std::multimap<ll, ll> myMap; // Key = resident cost, value = max who can share with.
        for(int ii = 0; ii < n; ++ii) {
            std::cin >> a;
            va[ii] = a;
        }

        for(int ii = 0; ii < n; ++ii) {
            std::cin >> b;
            vb[ii] = b;
            myMap.insert({vb[ii], va[ii]});
        }

        //for(auto pair : myMap) {
        //    std::cout << "first: " << pair.first << "  / sec: " << pair.second << std::endl;
        //}

        std::sort(vb.begin(), vb.end());

        // mr.P tell cheapest resident:
        --n;
        sum += p;

        while(n > 0) {
            if(!myMap.empty()) {
                auto cheapestResidentIt = myMap.begin(); // This is the actual cheapest in the map
                ll cheapResidentValue = cheapestResidentIt->first;
                ll howManyShares = cheapestResidentIt->second;

                // Check if cost cheap resident is cheaper than mr p.
                if(cheapResidentValue <= p) {
                    //std::cout << "cheapResidentValue: " << cheapResidentValue << "  / howManyShares: " << howManyShares << std::endl;

                    if(howManyShares > n) { // Cap.
                        howManyShares = n;
                    }
                    n -= howManyShares;
                    sum += (cheapResidentValue * howManyShares);

                    // erase map entry.
                    myMap.erase(cheapestResidentIt);
                    //std::cout << "n: " << n << "  / sum: " << sum << std::endl;

                } else { // No cheap residents.
                    //std::cout << "No cheap residents! " << std::endl;
                    if(n > 0) {
                        sum = sum + (p * n);
                        n = 0;
                    }
                }
            
            }

        }

        //std::cout << "sum: " << sum << std::endl;
        std::cout << sum << std::endl;

    }

}
