#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a(12);
	int k, res = 0, it = 0, max = 0, iPos = 0;
	cin >> k; 
	for(int i = 0; i < 12; ++i)
	  cin >> a[i];

	while (res < k) {
		for(int i = 0; i < 12; ++i) {
			if(a[i] > max) {
			  max = a[i];
			  iPos = i;
		    }
		}
		res += a[iPos];
		a[iPos] = 0;

		++it;
		max = 0;
		if(it > 12) {
			it = -1;
			break;
		}
	}
	cout << it << endl;
}
