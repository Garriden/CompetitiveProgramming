//https://codeforces.com/contest/2033/problem/A

//g++ -o hola hola.cpp
//Sakurako and Kosuke 
//Just chec f s even or odd.

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* pow */
#define ll unsigned long long
using namespace std;

int main() {
    ll t, n, CA;
    ll a;
    std::cin >> t;
    while(t--) {
        ll sum = 0;
        std::cin >> n;
        ll N = n;
        ll max = 0;
        //ll robinMoney = 0;
        //ll ZERO_COUNTS = 0;
        //    cout << endl;
        if(n%2 == 0) {
            std::cout << "Sakurako" << std::endl;
        } else  {
            std::cout << "Kosuke" << std::endl;
        }
        //std::cout << sum << std::endl;
    }

}