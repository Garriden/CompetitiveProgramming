#include <bits/stdc++.h>
using namespace std;

int main() {
int main() {
  	long long x, y;
  	cin >> x >> y;

	if(x == y) cout << "=" << endl;
	else if(x == 1) cout << "<" << endl;
	else if (y == 1) cout << ">" << endl;
	else {
		if(x > y) cout << "<" << endl;
		else if(x < y) cout << ">" << endl;
	}
  	  	
}
