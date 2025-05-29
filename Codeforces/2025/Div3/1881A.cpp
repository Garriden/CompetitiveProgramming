//https://codeforces.com/contest/1881/problem/A
// Div. 3
// 1
 
// Don't Try to Count
 
// g++ -o a a.cpp
 
// brute force
// strings
 
// if(mainString.find(subString1) != std::string::npos) {
 
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
 
int main() {
    ll t, n, m, x;
    ll a, b, p;
    std::string s1, s2;
    std::cin >> t;
 
    while(t --> 0) {
        std::cin >> x >> n;
        std::cin >> s1 >> s2;
        int cont = 0;
        bool found = false;
        std::string saux = s1;
 
        if(s1.find(s2) != std::string::npos) {
            //std::cout << "cont: " << cont << std::endl;
            std::cout << cont << std::endl;
            found = true;
        }
 
        while(!found && (s1.size() < n*2 || cont == 0)) {
            s1 += s1;
            ++cont;
            if(s1.find(s2) != std::string::npos) {
                std::cout << cont << std::endl;
                //std::cout << "cont: " << cont << std::endl;
                found = true;
                break;
            }
        }
 
        if(!found) {
            std::cout << -1 << std::endl;
        }
    }
 
}