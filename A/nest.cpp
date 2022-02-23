/*********************
https://codeforces.com/problemset/problem/71/A
A
800
strings
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k,n
	cin >> k >> n;
	
	int cont = 0;
	int ant = -24;
	int aux;
	while (n --> 0)
    {
        cin >> aux;
        if(aux > ant) {
            ant = aux;
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
