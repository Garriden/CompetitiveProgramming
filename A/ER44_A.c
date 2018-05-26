#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, aux,negras = 0, blancas = 0;
  cin >> n;
  vector<int> p(n/2);
  for(int i = 0; i < (n/2); ++i) {
    cin >> aux;
	p[i] = aux-1;
  }
  vector<bool> B(n);
  for(int i = 0; i < (n/2); ++i) {
	  B[p[i]] = 1;
	  if((p[i]%2) == 0) negras++;
	  else blancas++;
  }
  /*
  for(int i = 0; i < n; ++i)
    cout << B[i] << " ";
	*/
	int cont;
	bool empieza;
	
	
  aux = 0;
  cont = 0;
  empieza = true;
  for(int i = 0; i < (n-1); ++i) {
    if((B[i] == 1) && (B[i+1] == 1)) {
      ++aux;
      empieza = true;  
    }
    else if((aux > 0) && empieza){
	  ++cont;
	  empieza = false;
	}
	  
  }
  
  //cout << "cont: " << cont << endl;
  int cont2 = cont;
  int factorial = 0;
  while (cont > 0) {
   for(int i = 1; i <=(aux/cont2); ++i)
    {
        factorial += i;
    }
    --cont;
  }
  if((cont == 0) && empieza) {
	for(int i = 1; i <=aux; ++i)
    {
        factorial += i;
    }
    --cont;
	  
	  
  }
  
  
    //if(aux == 0) factorial = 0;
 //if(negras >= blancas) factorial = factorial-1;
 if((B[n-1] == 1) && (B[0] == 1)) ++factorial;
  if(n == 2) factorial = 0;
  cout << factorial << endl;
	
}
