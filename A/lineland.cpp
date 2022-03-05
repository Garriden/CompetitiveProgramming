/*********************
https://codeforces.com/problemset/problem/567/A
A

900
greedy
implementation
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> V(n);
    for(int ii = 0; ii < n; ++ii) {
        cin >> V[ii];   
    }
    
    long long max = -10000000000;
    long long min = 10000000000;
	
	for(int ii = 0; ii < n; ++ii) {
	    
	    for(int jj = 0; jj < n; ++jj) {
	        if(jj != ii) {
	            if( (V[jj] <= 0 && V[ii] <= 0) || (V[jj] >= 0 && V[ii] >= 0) ) {
	                if( abs((abs(V[jj]) - abs(V[ii]))) > max) {
	                    max = abs(abs(V[jj]) - abs(V[ii]));
	                    //cout << "aaaaa " << jj << ", " << ii << " | " << V[ii] << ". " << V[jj] << "   " << max << endl; 
	                }
	                if( abs(abs(V[jj]) - abs(V[ii])) < abs(min)) {
	                    min = abs( abs(V[jj]) - abs(V[ii]) );
	                    //cout << "aaaaa " << jj << ", " << ii << " | " << V[ii] << ". " << V[jj] << "   " << min << endl;   
	                }
	            } else if((V[jj] > 0 && V[ii] < 0) || ((V[jj] < 0 && V[ii] > 0)) ) {
	                if( abs((abs(V[jj]) + abs(V[ii]))) > max) max = abs(abs(V[jj]) + abs(V[ii]));
	                if( abs(abs(V[jj]) + abs(V[ii])) < abs(min)) min = abs(V[jj]) + abs(V[ii]);
	            }
	            
	        }
	    
	    }
	    cout << abs(min) << " " << abs(max) << endl;
	    max = -10000000000;
        min = 10000000000;
	}
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
