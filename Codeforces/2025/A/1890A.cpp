//https://codeforces.com/contest/1890/problem/A
// Div. 2
// 500  *800
 
// Doremy's Paint 3
 
// g++ -o a a.cpp
 
// constructive algorithms
 

/*
  1) All numbers are the same, like [3,3,3,3,3,3]. The answer is YES.
  2) There are two different numbers, like [1,2,1,2,1]
     The answer is YES if and only if one of the number appears exactly ⌊n/2⌋
    if one number appears more than one respect the other number, the answer is NO.
  3) There are three or more different numbers, like [1,2,3,2,3]. The answer is NO.
*/
// map: increase frequency -> elementFrequencies[v[0]]++;
// watchout when inputing the vector, if I want to check the element before,
//  I need to process element 0 first and start the for at index 1.
 
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
 
    std::vector<int> v(n);
 
    std::map<int,int> elementFrequencies;
 
    std::cin >> v[0];
    int before = v[0];
    elementFrequencies[v[0]]++;
    bool equal = true;
    for(int ii = 1; ii < n; ++ii) {
        std::cin >> v[ii];
 
        elementFrequencies[v[ii]]++;
 
        if(equal && v[ii] != before) {
            equal = false;
        }
        before = v[ii];
    }
 
    if(equal || n <= 2) {
        std::cout << "Yes" << std::endl;
        return;
    }
 
    //for(auto pair : elementFrequencies) {
    //    std::cout << "element: " << pair.first << "  / freq: " << pair.second << std::endl;
    //}
 
    if(elementFrequencies.size() > 2) { // 1 1 4 5
        std::cout << "No" << std::endl;
        return;
    } else { // 2 3 3 3 3
        ll sum = 0;
        int cont = 0;
        for(auto it = elementFrequencies.begin(); it != elementFrequencies.end(); ++it) {
            if(cont % 2 == 0) {
                sum += it->second;
            } else {
                sum -= it->second;
            }
            ++cont;
            //std::cout << "sum: " << sum << std::endl;
        }
        if(std::abs(sum) > 1) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
 
 
 
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