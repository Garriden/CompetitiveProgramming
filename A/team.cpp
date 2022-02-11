/*********************
https://codeforces.com/problemset/problem/231/A
A
800

greedy
brute force
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int cont = 0;

void solve() {
    int a,b,c;
	cin >> a >> b >> c;
	
    if(a+b+c > 1) {
        cont++;
    }

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
		
	cout << cont << endl;
}
