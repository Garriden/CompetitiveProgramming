#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "=" << endl;
	}else {
		double lx = log10(x); double ly = log10(y);
		if (lx * y < ly * x) cout << "<" << endl;
		else if (lx * y > ly * x) cout << ">" << endl;
		else cout << "=" << endl;
	}
}
