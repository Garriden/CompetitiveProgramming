/*********************
https://codeforces.com/contest/1633/problem/A
A

brute force
constructive algorithms

3
42
23
377
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
	cin >> n;
	if (n%7 == 0) cout << n << endl;
	else {
	    n = n / 10;
	    int aux = n;
	    for (int ii = 0; ii < 10; ++ii) {
	        int naux = aux*10+ii;
	        if (naux%7 == 0) {
	            cout << naux << endl;
	            return;
	        }
	    }
	    
	    
	    
	}

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
