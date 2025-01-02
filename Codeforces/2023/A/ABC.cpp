/*********************
https://codeforces.com/contest/1632/problem/A
A
implementation
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
	cin >> n;
	string s;
	cin >> s;
	
        if(s == "0" || s == "1" || s == "01" || s == "10") {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
