/*********************
https://codeforces.com/problemset/problem/996/A
A
800

greedy
dp
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
	cin >> n;
	
	int cont = 0;
	
	while(n >= 100) {
	    n -= 100;
	    cont++;
	}

	while(n >= 20) {
	    n -= 20;
	    cont++;
	}
	
	while(n >= 10) {
	    n -= 10;
	    cont++;
	}
	
	while(n >= 5) {
	    n -= 5;
	    cont++;
	}
	
	while(n >= 1) {
	    n --;
	    cont++;
	}
	
	cout << cont << endl;
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
