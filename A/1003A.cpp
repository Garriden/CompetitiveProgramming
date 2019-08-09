// #494 Div. 3
// A 700
// implementation	

#include <iostream>
#include <vector>

int main() {
	int n, m;
	int rep = 0;
	std::cin >> n;
	std::vector<int> in(n);
	std::vector<int> accum(101);
	for(int ii = 0; ii < n; ++ii) {
		std::cin >> m;
		accum[m]++;
		if(accum[m] > rep) {
			rep = accum[m];
		}
	}
	std::cout << rep << std::endl;
}
