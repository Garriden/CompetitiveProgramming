#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,m,cont=0,pila=0,j=0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
	  cin >> a[i];
	  
	cin >> m;
    vector<int> q(m);
    for(int i = 0; i < m; ++i) 
	 cin >> q[i];
	 
	for(int i = 0; i < n; ++i) {
		pila += a[i];
		a[i] = pila;
	}
	
	vector<int> b(pila);
	for(int i = 0; i < pila; ++i) {
	  if(i == a[cont]) ++cont;
	  b[i] = cont;	  
    }

	 
	for(int i = 0; i < m; ++i)  {	  
	  cout << b[q[i]-1]+1 << endl;	
	}
}
