// #492 Div. 2
// A 900
// Implementation

#include <iostream>
#include <vector>

int main() {
	int n, d;
	std::cin >> n >> d;
    std::vector<int> V(n);
    
    int res = 1;
    for(int ii = 0; ii < n; ii++) {
        std::cin >> V[ii];
    }
    int lastPos = V[0] + d + 1;
    if((n > 1) && ((V[0] + d) <= (V[1] - d))) {
        //std::cout << "Pos: " << (V[0] + d) << std::endl;
        ++res;
    }
    
    for(int ii = 1; ii < n-1; ii++) {
        if((V[ii] - d) >= lastPos) {
            //std::cout << "Pos: " << (V[ii] - d) << std::endl;
            ++res;
        }
        
        if((V[ii] + d) < (V[ii+1] - d)) {
            //std::cout << "Pos: " << (V[ii] + d) << std::endl;
            ++res;
        }
        lastPos = V[ii] + d;        
    }
   
    if((V[n-1] - d) >= lastPos) {
        //std::cout << "Pos: " << (V[n-1] - d) << std::endl;
        ++res;
    }

    std::cout << ++res << std::endl;	
}
