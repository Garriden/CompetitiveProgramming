//https://codeforces.com/contest/2065/problem/A
// Div. 4

//g++ -o a a.cpp

//Sakurako and Kosuke 
//Just substring.

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

        std::string sAux = s.substr(0, s.size()-2);

        std::cout << sAux + "i" << std::endl;
    }

}