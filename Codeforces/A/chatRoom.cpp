/*********************
https://codeforces.com/problemset/problem/71/A
A

1000
greedy
strings
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	
	int cont = 0;
	for(int ii = 0; ii < s.size(); ++ii) {
	    switch(cont) {
	        case 0:
	            if(s[ii] == 'h') cont++;
	            break;
	        case 1:
	            if(s[ii] == 'e') cont++;
	            break;
	        case 2:
	            if(s[ii] == 'l') cont++;
	            break;
	        case 3:
	            if(s[ii] == 'l') cont++;
	            break;
	        case 4:
	            if(s[ii] == 'o') cont++;
	            break;
	    }
	    
	}
	
	if(cont >= 5) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
