//https://codeforces.com/contest/2065/problem/B
// Div. 4

//g++ -o b b.cpp

// Skibidus and Ohio 
// Just check string.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>       /* pow */
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA;
    ll a;
    std::string s;
    std::cin >> t;
    while(t--) {
        std::cin >> s;
        char last = s[0];
        bool found = false;

        for(int ii = 1; ii < s.size() && !found; ++ii) {
            if(s[ii] == last) {
                std::cout << "1" << std::endl;
                found = true;
            }
            last = s[ii];
        }

        if(!found) {
            std::cout << s.size() << std::endl;
        }
    }

}