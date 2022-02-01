/*********************
https://codeforces.com/contest/1633/problem/B
B

greedy

4
01
1010101010111
00110001000
1
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    string s;
	cin >> s;
	long long ones=0, zeros=0;
    	    
    for (int ii = 0; ii < s.length(); ++ii) {
	    if(s[ii] == '1') ones++;
	    else zeros++;
	    
	}
	if (zeros == ones) cout << ones-1;
	else if (zeros > ones) cout << ones;
	else cout << zeros; 

    cout << endl;
}

int main() {
	long long T;
	cin >> T;
	while (T--)
		solve();
}
