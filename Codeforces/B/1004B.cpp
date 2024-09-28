// #492 Div. 2
// B 1400
// Constructive algorithms, Greedy
//  Implementation, Math.

#include <iostream>
#include <vector>

void printVector(std::vector<int> &v) {
	for(int ii = 0; ii < (int)v.size(); ii++) {
		std::cout << v[ii];
	}
}

int main() {
    int n, m, li, ri;
    std::cin >> n >> m;
    std::vector<int> V(n, 0);
    for(int ii = 0; ii < m; ++ii) {
        std::cin >> li >> ri;
        for(int jj = li-1; jj < ri; ++jj) {
            if((jj % 2) == 0) {
                V[jj] = 0;
            } else {
                V[jj] = 1;
            }
        }
    }
    printVector(V);
}
