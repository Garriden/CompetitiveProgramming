// #579 Div. 3
// B 1200
// Greedy, Math

#include <iostream>
#include <vector>

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

int main() {
    int q, n;
    std::cin >> q; 

    for(int ii = 0; ii < q; ++ii) {
        bool error = false;
        std::cin >> n;
        std::vector<int> V(n * 4);
        for(int jj = 0; jj < (int)V.size(); ++jj) {
            std::cin >> V[jj];
        }
        
        insertionSort(V);
        //printVector(V);
        int area = V[0] * V[V.size() - 1];

        for(int jj = 0; (jj < n) && !error; ++jj) {
            // Mike
            int lf = jj * 2, rg = 4 * n - (jj * 2) - 1;
			if (V[lf] != V[lf + 1] || V[rg] != V[rg - 1] || V[lf] * 1ll * V[rg] != area) {
				error = true;
			}
        }
    
        if(error) {
            std::cout << "NO";
        } else {
            std::cout << "YES";
        }
        std::cout << std::endl;
        error = false;
    } 
   
}
