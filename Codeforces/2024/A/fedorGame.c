#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n,m,k,Fedor;
	cin >> n >> m >> k;
	vector<int> X(m);
	vector<int> Xb(m+1);
	for(int i = 0; i < m; ++i) 
	  cin >> X[i];
	for(int i = 0; i < m; ++i)
	  Xb[i] = 0;
	cin >> Fedor;

	int f;
	int cont = 0, aux = 0;
	for(int i = 0; i < m; ++i)  {
		f = X[i]^Fedor;
		for(int j = n; j >= 0; j--) {
		  if(((f >> j) & 1) == 1) aux++;
	
		}
		if(aux <= k) cont++;
		//if(abs(FedorB-Xb[i]) <= k) cont++;
		aux = 0;
	}

	  cout << cont << endl;
		
}
