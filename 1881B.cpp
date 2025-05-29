//https://codeforces.com/contest/1881/problem/B
// Div. 3
// 2

// Three Threadlets

// g++ -o b b.cpp

// math

// Check test case: 6 6 9
// I forgot to add the resultant number into the array (9 converts to 6 and 3).
// Don't be clever trying to do math tricks when you could just iterate. Do the entire algorithm!

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

int main() {
    ll t, n, m, x;
    ll a, b, c, p;
    std::string s1, s2;
    std::cin >> t;

    while(t --> 0) {
        std::vector<ll> v(3);
        std::cin >> a >> b >> c;

        v[0] = a;
        v[1] = b;
        v[2] = c;
        std::sort(v.begin(), v.end());

        int cont = 0;
        int found = false;

        if(v[0] == v[v.size() - 1]) {
            std::cout << "YES" << std::endl;
        } else {

            for(int ii = 0; ii < 3; ++ii) {
                v[v.size() - 1] -= v[0];
                v.push_back(v[0]); // resultant number from operation before.
                std::sort(v.begin(), v.end());

                //for(int ii = 0; ii < v.size(); ++ii) {
                //    std::cout << v[ii] << " ";
                //} std::cout << std::endl;

                if(v[0] == v[v.size() - 1]) {
                    found = true;
                    break;
                }

            }

            if(found) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }


        }

    }

}
