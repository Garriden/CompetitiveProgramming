// #494 Div. 3
// D 1600
// greedy	
 
#include <iostream>
#include <vector>
#include <math.h>

void printVector(std::vector<int> &v) {
    for(int ii = 0; ii < (int)v.size(); ii++) {
        std::cout << v[ii] << " ";
    }
}

void swap(std::vector<int> &v, int posO, int posD) {
    int aux = v[posO];
    v[posO] = v[posD];
    v[posD] = aux;
}

void insertionSort(std::vector<int> &vec) {
    int pos = vec.size() -1;
    int pos_aux = pos - 1;
    while(pos >= 0) {
        while(pos_aux >= 0) {
            if(vec[pos] > vec[pos_aux]) {
                swap(vec, pos, pos_aux);
            }
            pos_aux--;
        }
        --pos;
        pos_aux = pos - 1;
    }	
}

void invert(std::vector<int> &vec) {
	for(int ii = 0; ii < (int)(vec.size()/2); ++ii) {
		swap(vec, ii, vec.size() - ii - 1);
	}
}

int binaryPosition(int n) {
    if(n == 1) {
        return 0;
    } else {
        for(int ii = 31; ii > 0; --ii) {
            if((n % (1 << ii)) == 0) {
                return ii;
            }
        }
        return -1;
    }    
}

int main() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> V(31);

	for(int ii = 0; ii < n; ii++) {
        int x;
		std::cin >> x;
        V[binaryPosition(x)]++; // store the 2power.
	}

	int res = -1;
	for(int ii = 0; ii < q; ++ii) {
		std::cin >> n;
        res = 0;
        for(int jj = V.size()-1; jj >= 0 && n > 0; --jj) {
            int times = n / (1 << jj); // how many are needed
            if(V[jj] < times) { // and I have so many?
                times = V[jj];
            }
            res += times;
            n -= (1 << jj) * times; // pow2
        }			
        if(n > 0) {
            res = -1;
        }		
		std::cout << res << std::endl;
	}
}
