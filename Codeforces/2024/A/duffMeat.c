#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  vector<int> p(n);
  
  for(int i = 0; i < n; ++i) {
	  cin >> a[i];
	  cin >> p[i];
  }
  
  int res = 0, minPrice = p[0];
  
  res = a[0]*minPrice;
  
  for(int i = 1; i < n; ++i) {
	if(p[i] < minPrice)
	  minPrice = p[i];
	 
	res += a[i]*minPrice; 
	  
  }
	
  cout << res << endl;
}
