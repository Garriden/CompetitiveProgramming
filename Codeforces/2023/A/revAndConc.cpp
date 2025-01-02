/*********************
https://codeforces.com/contest/1634/problem/A
A
brute force
strings
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	if(m == 0) {
	    cout << "1" << endl;
	    return;
	}
	
	for(int ii = 0; ii < (s.length()/2); ii++) {
	    if(s[ii] != s[s.length()-1-ii]) {
	        cout << "2" << endl;
	        return;
	    }
	    
	}
    cout << "1" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
