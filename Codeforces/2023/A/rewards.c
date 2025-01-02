#include <iostream>
using namespace std;

int main() {
	int a1,a2,a3,b1,b2,b3,n;
	bool res = true;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	
	int a = a1+a2+a3;
	int b = b1+b2+b3;
	
	double Da = (double)a/5;
	double Db = (double)b/10;
	

	if (Da > (a/5)) 
	  Da = (a/5)+1;
	if (Db > (b/10)) 
	  Db = (b/10)+1;

	if((n == 1) && ((a==0) || (b==0)) &&((Da+Db) <= n)) res = true;
	else if(n < 2) res = false;
	else if((Da+Db) > n) res = false;
	//else if()
	
	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;
}
