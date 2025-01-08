/*********************
https://codeforces.com/problemset/problem/158/A
A
800

greedy
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k,n;
	cin >> k >> n;
	
	int cont = 0;
	int aux;
	while (k --> 0)
    {
        cin >> aux;
        if(aux >= n) {
            ++cont;
        }
    }
    
    cout << cont << endl;
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
