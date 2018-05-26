#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) 
	cin >> a[i];
	
  sort(a.begin(), a.begin()+n);
  
  cin >> m;
  vector<int> b(m);
  for(int i = 0; i < m; ++i) 
	cin >> b[i];
	
  sort(b.begin(), b.begin()+m);
  
  int cont = 0, x, n1;
  if(m < n)
    n1 = m;
  else n1 = n;
  
  int aI = 0, bI = 0;
  
  while((aI < n) && (bI < m)) {
	x = a[aI] - b[bI];
    if((x == -1) || (x == 0) || (x == 1)) {
	  ++cont;
	  aI++;
	  bI++;
	}
	else {
      if(a[aI] < b[bI]) {
        aI++;
	  }
	  else {
	    bI++;
	  }
	}
	  
  }
    
  cout << cont << endl;
  
}
