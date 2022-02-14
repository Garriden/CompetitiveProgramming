/*********************
https://codeforces.com/problemset/problem/339/A
A
800

greedy
implementation
sortings
strings
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    string s;
	cin >> s;
	
	int ones = 0, twos = 0, threes = 0;

	while(s.length() > 1) {
	    string aux;
        aux = s.substr(s.length()-2,s.length());
    	aux = aux.substr(1,2);
	    if(aux == "1") {
	        ones++;
	    } else if(aux == "2") {
	        twos++;
	    } else {
	        threes++;
	    }
	    s = s.substr(0,s.length()-2);
	}
	
	if(s == "1") {
	    ones++;
	} else if(s == "2") {
	    twos++;
	} else {
	    threes++;
	}
	
	string ret = "";
	while(ones --> 0) {
	    ret += "1";
	    if(ones > 0) ret +="+";
	    else if(ones == 0 && (twos!= 0 || threes!= 0) ) ret +="+";
	}
	while(twos --> 0) {
	    ret += "2"; 
	    if(twos > 0) ret +="+";
	    else if(twos == 0 && threes!= 0) ret +="+";
	}
	while(threes --> 0) {
	    ret += "3"; 
	    if(threes > 0) ret +="+";
	}
	
	cout << ret;
	
}

int main() {
	//int T;
	//cin >> T;
	//while (T--)
		solve();
}
