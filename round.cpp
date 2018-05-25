#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, aux;
  cin >> n;
  

  if(n < 6) n = 0;
  else if ((n > 5) && (n < 10)) n = 10;
  else if(n > 9) { 
	aux = n%10;
	n = n/10;
	
	if(aux > 5) ++n;
    n = n*10;
  }
  


  
  cout << n << endl;
}
