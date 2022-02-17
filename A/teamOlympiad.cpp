/*********************
https://codeforces.com/problemset/problem/490/A
A
800

greedy
implementations
sortings
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t;
	cin >> n;
	
	int cont = 1;
	
	vector<int> ones;
	vector<int> twos;
	vector<int> threes;

	while(n --> 0) {
	    cin >> t;
	    if(t == 1) {
	        ones.push_back(cont++);
	    } else if(t == 2) {
	        twos.push_back(cont++);
	    } else if(t == 3) {
	        threes.push_back(cont++);
	    }
	}

	int min = std::min({ones.size(), twos.size(), threes.size()});
	
	cout << min << endl;
	
	cont = 0;
	
	while(min --> 0) {
	    cout << ones[cont] << " " << twos[cont] << " " << threes[cont] << endl;
	    cont++;
	}
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
