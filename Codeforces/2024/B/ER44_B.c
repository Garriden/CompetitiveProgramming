#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<char> > M(n, vector<char>(m));
  vector<bool> exc(m);
  
  int cont = 0;
  bool YES = false;
  bool vamonos = false;
  char c;
  for(int i = 0; i < n;++i) {
	  for(int j = 0; j < m;++j) {
	    cin >> c;
	    M[i][j] = c;
 	  }
  }
  
  for(int j = 0; j < m;++j) {
	  for(int i = 0; i < n;++i) {
		 if(M[i][j] == '1') ++cont;  
	  }  
 	  if(cont == 1) exc[j] = true;
 	  else exc[j] = false;
 	  cont = 0;
  }
  
  int contExc = 0;
	for(int i = 0; ((i < n) && !YES);++i) {
	  for(int j = 0; j < m;++j) {
	    if((M[i][j] == '1') && (exc[j])) ++contExc;
 	  }
 	  if(contExc == 0) YES = true;
 	  contExc = 0;
    }
  
  
 
	if(YES) cout << "YES" << endl;
	else cout << "NO" << endl;
  
  
}
