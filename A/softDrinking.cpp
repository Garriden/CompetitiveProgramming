/*********************
https://codeforces.com/problemset/problem/151/A
A
800

implementation
math
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>    // std::min
using namespace std;

int main() {
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int mililiters = k*l;
    int limes = c*d;
    int toasts = mililiters / nl;
    int salt = p / np;
    
    int min = std::min(toasts, limes);
    min = std::min(min, salt);
    
    cout << min/n << endl;
}
