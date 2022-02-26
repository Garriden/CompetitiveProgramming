/*********************
https://codeforces.com/problemset/problem/320/A
A
900

brute force
implementation
*************************/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
	cin >> s;
	
	int ii = 1;
	int ant = s[0];

	if(ant != 49) {
        cout << "NO" << endl;
        //cout << "a1" << endl;
        return;
    }
	
    while(ii < s.length()) {
        if(s[ii] != '1' && s[ii] != '4') {
            cout << "NO" << endl;
            //cout << "a2" << endl;
            return;
        } else if(ant != 49 && s[ii] == '4') {
            if(ant != 52) {
                cout << "NO" << endl;
                //cout << "a3" << endl;
                return;
            }
        }
        else if(ant == 52 && s[ii] == '4') {
            if(s[ii-2] != '1') {
                cout << "NO" << endl;
                //cout << "a4" << endl;
                return;
            }
        }
        
        ant = s[ii];
        ii++;
    }

	cout << "YES" << endl;

}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
