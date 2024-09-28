#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int cuantasShovels(int k, int r) {
	int i = 1;
	int n = k;
	
	if((k == 10) || (k == r)) 
	  return i;

	while (1) {
		if((n%10 == 0) || (n%10 == r)) return i;
		else n = n+k;
		
		++i;
	}
}

int main() {
	optimize();
	int k, r;
	cin >> k >> r;
	
	cout << cuantasShovels(k,r) << endl;

}
