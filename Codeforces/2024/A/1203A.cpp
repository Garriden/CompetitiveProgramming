// #579 Div. 3
// A 1100
// Implementation

#include <iostream>

int main() {
    int q, n, x, first, lastN;
    std::cin >> q;
    int counterClock = 0;
    int clock = 0;
    
    for(int ii = 0; ii < q; ++ii) {
        std::cin >> n;
        for(int jj = 0; (jj < n); ++jj) {
            std::cin >> x;
            if(jj == 0) {
                first = x;
            } else {
                if(lastN != (x - 1)) {
                    clock++;
                }
                if(lastN != (x + 1)) {
                    counterClock++;
                }
            }  
            lastN = x;
            //std::cout << "clock: " << clock << std::endl;
            //std::cout << "CounterClock: " << counterClock << std::endl;
        }  
        
        if(x != (first - 1)) {
            clock++;
        } else if(x != (first + 1)) {
            counterClock++;
        }      
        
        if((clock < 2) || (counterClock < 2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
        
        clock = 0;
        counterClock = 0;
    
    } 
   
}
