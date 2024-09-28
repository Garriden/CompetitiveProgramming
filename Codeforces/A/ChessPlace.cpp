#include <bits/stdc++.h>
using namespace std;

int difPos(int origen,int destino) {
	return abs(destino - origen);
}

int main() {
  int n;//, negras = 0, blancas = 0;
  cin >> n;
  int aux;
	  
  vector<int> p(n/2);
  for(int i = 0; i < (n/2); ++i) {
	cin >> aux;
    p[i] = aux-1;
  }
  
  sort(p.begin(), p.end());
  

  int blancas = 0, negras = 0;
  for(int i = 0; i < n/2; i++) {
	  blancas += difPos(p[i],i*2);
	  negras += difPos(p[i],(i*2)+1); 
  }	
  
   cout << min(negras,blancas) << endl;
	
}
