#include <bits/stdc++.h>
using namespace std;

int main() {
  	int n;
	cin >> n;
	string s;
	vector<string> N(6);
	vector<bool> B(6);
	N[0] = "Power";
	N[1] = "Space";
	N[2] = "Soul";
	N[3] = "Mind";
	N[4] = "Time";
	N[5] = "Reality";
	for(int i = 0; i < 6; ++i) B[i] = false;
	
	for(int i = 0; i < n; ++i) {
		cin >> s;
		if(s == "purple") B[0] = true;
		else if(s == "green") B[4] = true;
		else if(s == "blue") B[1] = true;
		else if(s == "orange") B[2] = true;
		else if(s == "red") B[5] = true;
		else if(s == "yellow") B[3] = true;
	}


	cout << 6-n << endl;
	
	for(int i = 0; i < 6; ++i) {
		if(!B[i]) cout << N[i] << endl;
		
	}
	

}
