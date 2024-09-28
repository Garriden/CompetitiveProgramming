/*********************
https://codeforces.com/problemset/problem/1291/A
A

900
greedy
math
strings
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
	string s;
	cin >> s;
	int even = -1;
	bool eben = false;

	for(int ii = 0; ii < x; ++ii) {
	    
	        if(even > -1){
    	        if (s[ii]%2 == 0 && s[ii] != 0) {
    	            cout << "even" << endl;
    	            even = s[ii];
    	        }
	        } else {
	            if (s[ii]%2 == 0 && s[ii] != 0) {
    	            cout << "even" << endl;
    	            eben = true;
    	            even = even*10 + s[ii];
    	            break;
    	        }
	            
	        }
	        
	}
	if(eben) cout << even << endl;
	else cout << "-1" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
