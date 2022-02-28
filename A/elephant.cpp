/*********************
https://codeforces.com/problemset/problem/617/A
A

800
math
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cont = 0;
    while(n>0) {
        n -= 5;
        ++cont;
    }
	cout << cont << endl;

}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
