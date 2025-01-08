/*********************
https://codeforces.com/problemset/problem/469/A
A
800

greedy
implementation
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n, a;
	cin >> n;
	
	vector<bool> V(n, true);
	
	int p;
	cin >> p;
	while(p --> 0) {
	    cin >> a;
	    V[a-1] = false;
	}
	
	int q;
	cin >> q;
	while(q --> 0) {
	    cin >> a;
	    V[a-1] = false;
	}
	/*
	for(int ii = 0; ii < V.size(); ++ii) {
	    cout << V[ii] << endl;
	}
	*/
	for(int ii = 0; ii < V.size(); ++ii) {
	    if (V[ii]) {
	        cout << "Oh, my keyboard!" << endl;
	        return;
	    }
	    
	}
	
	cout << "I become the guy." << endl;
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
