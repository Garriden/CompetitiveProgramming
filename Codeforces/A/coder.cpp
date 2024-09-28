#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,j;
	cin >> n;
	bool ara = true;
	bool parell = false;
	
	if(n%2 == 0) {
	  parell = true;
	  if(n == 2) cout << 2 << endl;
	  else cout << n*(n/2) << endl;
    }
	else cout << ((n/2)+1)*((n/2)+1) + (n/2)*(n/2) << endl;
	
	for(i=n;i--;) {
	  for(j=n;j--;) {
	    if(ara) cout << 'C';
	    else cout << '.';
	    ara = !ara;	    
	  }
	  if(parell) ara = !ara;
	  cout << endl;
    }
	
}
