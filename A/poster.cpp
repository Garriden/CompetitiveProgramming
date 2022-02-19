/*********************
https://codeforces.com/problemset/problem/412/A
A
900

greedy
implementations
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
    int LEFT_MOST = 1;
    int RIGHT_MOST = s.length();
    
    int goRight = RIGHT_MOST - k;
    int goLeft = k - LEFT_MOST;

    
    if(goRight < goLeft) {
        while (k < RIGHT_MOST) {
            ++k;
            cout << "RIGHT" << endl;
        }
        while (k >= LEFT_MOST) {
            cout << "PRINT " << s[k-1] << endl;
            --k;
            if(k >= LEFT_MOST) {
                cout << "LEFT" << endl;
            }
        }
    } else {
        while (k > LEFT_MOST) {
            --k;
            cout << "LEFT" << endl;
        }
        while (k <= RIGHT_MOST) {
            cout << "PRINT " << s[k-1] << endl;
            ++k;
            if(k <= RIGHT_MOST) {
                cout << "RIGHT" << endl;
            }
        }
    
    }
	
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
