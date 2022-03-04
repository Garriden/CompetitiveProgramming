/*********************
https://codeforces.com/problemset/problem/567/A
A

900
greedy
implementation
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> V(n);
    for(int ii = 0; ii < n; ++ii) {
        cin >> V[ii];   
    }
    
    long long max = -10000000000;
    long long min = 10000000000;
	
	for(int ii = 0; ii < n; ++ii) {
	    
	    for(int jj = 0; jj < n; ++jj) {
	        if(jj != ii) {
	            if(V[jj] + V[ii] > max) max = V[jj] + V[ii];
	            if(V[jj] + V[ii] < min) min = V[jj] + V[ii];
	        }
	    
	    }
	    cout << min << " " << max << endl;
	    max = -10000000000;
        min = 10000000000;
	}
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
