/*********************
https://codeforces.com/contest/1632/problem/B
B

permutation
bitmasks
constructive algorithms
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
	cin >> n;
	
	int min = n;

        int k = 0;
        while((1 << (k + 1)) <= n - 1) ++k; 
        
        for(int i = (1 << k) - 1; i >= 0; i--) {
            cout << i << ' ';
        }
        for(int i = (1 << k); i < n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
