/*********************
https://codeforces.com/contest/1637/problem/A
A

sortings
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
	cin >> n;

    vector<int> a(n);
    for (auto& u : a)
        cin >> u;
    if (!is_sorted(a.begin(), a.end()))
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
