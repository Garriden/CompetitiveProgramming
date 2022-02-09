/*********************
https://codeforces.com/contest/1634/problem/B
B

bitmasks
math
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    long long n, x, y;
	cin >> n >> x >> y;

	long long ret = 0;
	while(n --> 0) {
	    long long a;
	    cin >> a;
	    ret += a;
	}
	if( ((ret + x + y) % 2) == 0) cout << "Alice" << endl;
	else cout << "Bob" << endl;

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
