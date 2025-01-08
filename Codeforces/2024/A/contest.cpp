#include <bits/stdc++.h>
using namespace std;

// >= 2400 					-- red
// 2200 <= x < 2400 -- oragne

int main() {
  int n, n1, n2, i;
	cin >> n;
	string s;

	bool fuera = false;
	
	for(i=n;i--;) {
		cin >> s;
		cin >> n1 >> n2;
		
	  if((n1 >= 2400) && (n2 > n1)) fuera = true;	
	}
	if(fuera) cout << "YES" << endl;								
	else cout << "NO" << endl;
}
