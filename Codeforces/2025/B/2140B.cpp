// https://codeforces.com/contest/2140/problem/B
// Div. 2
// 1000

// Another Divisibility Problem

// g++ -o b b.cpp

///////////////////////////////////////
//    String of d nines
// always divisible by 3
///////////////////////////////////////

// math !
// number theory
// constructive algorithms ?

// Uff see apuntes for the magic formula.
// Basically Catch that we need to do some tricks with the number of digits.
// Factorize and convert:
// x * 10^d   ->   x * (10^d - 1)  <- this is the string of d nines
// this string of nines could be simply converted into 3x

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;

    std::cin >> x;
/*
    ll yeet = 2 * x;

    ll res = 1;
    ll yAux = yeet;
    while(yAux > 0) { // Digit count building concatenation.
        res *= 10;
        yAux /= 10;
    }

    ll concat = (x * res) + yeet;
    if((concat % (x + yeet)) == 0) {
        std::cout << yeet << std::endl;
        return;
    }
*/
    std::cout << 2*n << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
