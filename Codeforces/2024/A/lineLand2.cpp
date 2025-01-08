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
    vector<int> V(1000000000);
    
    int n;
    cin >> n;

    for(int ii = 0; ii < n; ++ii) {
        cin >> V[ii];   
    }

	for(int ii = 0; ii < n; ++ii) {
	    if (ii == 0) {
            cout << V[1] - V[0] << " " << V[n - 1] - V[0] << endl;
        } else if (ii == (n - 1)) {
            cout << V[n - 1] - V[n - 2] << " " << V[n - 1] - V[0] << endl;
        } else {
    	    cout << min(V[ii + 1] - V[ii], V[ii] - V[ii - 1]) << " " << max(V[ii] - V[0], V[n - 1] - V[ii]) << endl;
        }
	}
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
