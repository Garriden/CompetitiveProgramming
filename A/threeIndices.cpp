/*********************
https://codeforces.com/problemset/problem/1380/A
A 900
brute force      
data structures

3
4
2 1 4 3
6
4 6 1 2 5 3
5
5 3 1 2 4
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


const int N = 1000;

int n;
int a[N];

void solve() {
	cin >> n;
	for (int ii = 0; ii < n; ++ii) cin >> a[ii];
	
	for (int ii = 1; ii < n - 1; ++ii) {
		if (a[ii] > a[ii - 1] && a[ii] > a[ii + 1]) {
			cout << "YES" << endl;
			cout << ii << ' ' << ii + 1 << ' ' << ii + 2 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
