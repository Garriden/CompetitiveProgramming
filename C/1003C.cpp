// #494 Div. 3
// C 1300
// Brute force, implementation, math

#include <iostream>
#include <vector>

int main() {
	double n, k;
	std::cin >> n >> k;
	std::vector<int>temp(n);
	double maxTemp = 0, partialTemp = 0;
	
	for(int ii = 0; ii < n; ++ii) {
		std::cin >> temp[ii];
	}
	
	for(int ii = k; ii <= n; ++ii) {
		for(int jj = 0; jj < n; ++jj) {
			partialTemp += temp[jj];
			if(jj >= ii) {
				partialTemp -= temp[jj-ii];
			}
			
			if((partialTemp/ii) > maxTemp) {
				maxTemp = partialTemp/ii;
			}
			//printf("maxTemp: %f\n", maxTemp);
		}
		partialTemp = 0;		
	}
	printf("%.8f\n", maxTemp);
}
