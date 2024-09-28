/*********************
https://codeforces.com/problemset/problem/1399/A
A
800

greedy
sortings
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
	cin >> n;
	
	int aux = 0;
	
	vector<int> a(n);

	while(n --> 0) {
	    cin >> a[n];
	}
	
	std::sort(a.begin(), a.end());  

    for(int ii = 1; ii < a.size(); ++ii) {
        //cout << a[ii] << endl;
        if( (a[ii] - a[ii-1]) > 1) {
            cout << "NO" << endl;
            return;
        }
    } 
    cout << "YES" << endl;

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
