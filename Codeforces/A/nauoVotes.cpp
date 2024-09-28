/*********************
https://codeforces.com/problemset/problem/1173/A
A
900

greedy
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c;
	cin >> a >> b >> c;
	
	int positive = 0;
	
	if(a > b) positive = 1;
	else if(b > a) positive = -1;

    if(positive > 0) {
        if((b+c) >= a) cout << "?" << endl;
        else cout << "+" << endl;
    } else if(positive < 0) {
        if((a+c) >= b) cout << "?" << endl;
        else cout << "-" << endl;
    } else {
        if((a+c) > b) cout << "?" << endl;
        else if((b+c) > a) cout << "?" << endl;
        else cout << "0" << endl;
    }
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
