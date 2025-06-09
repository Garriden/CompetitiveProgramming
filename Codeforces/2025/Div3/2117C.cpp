//https://codeforces.com/contest/2117/problem/C
// Div. 3
// 

// Cool Partition

// g++ -o c c.cpp

// data structures
// greedy

// Two vector bool, current and visited. (set of ints instead!)
// The tests given are not good for my implementation.
// Make your own tests!

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve() {
    ll n, m, x, k;
    ll a, b, p;
    std::string s;
    std::cin >> n;
    //std::cin >> s;

    int contPartitions = 0;

    std::vector<int> v(n);
    //std::vector<bool> firstPartition(n+1, false);  // current.
    //std::vector<bool> secondPartition(n+1, false); // seen or visited.
    std::set<int> firstPartition;
    std::set<int> secondPartition;
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> v[ii];
        //firstPartition[v[ii]] = true;
        //secondPartition[v[ii]] = true;
        firstPartition.insert(v[ii]);
        secondPartition.insert(v[ii]);

        if(firstPartition == secondPartition) {
            //std::cout << "secondPartition  equal FirstPartition " << std::endl;
            ++contPartitions;
            //secondPartition.assign(n + 1, false);
            secondPartition.clear();
        }

    }

        //std::cout << "contPartitions: " << contPartitions << std::endl;
        std::cout << contPartitions << std::endl;

}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
