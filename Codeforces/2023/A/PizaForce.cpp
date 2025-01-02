/*********************
https://codeforces.com/problemset/problem/1555/A
A 900
brute force      
math

6
12
15
300
1
9999999999999999
3
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t --> 0) {
        long long n;
        cin >> n;
        if(n < 6) n = 6;
        cout << (n+1)/2 * 5 << endl;
        
    }

    return 0;
}
