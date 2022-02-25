/*********************
https://codeforces.com/problemset/problem/282/A
A

800
implementation
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cont=0;
    
    while(n-->0) {
        string s;
	    cin >> s;
	    if(s == "++X" || s == "X++") ++cont;
	    else --cont;
    }
	cout << cont << endl;

}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
