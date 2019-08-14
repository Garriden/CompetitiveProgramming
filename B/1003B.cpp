// #494 Div. 3
// B 1000
// constructive algorithms

#include <iostream>
#include <vector>
 
int a, b, x;
int lastPosAux = 1;
 
bool printA() {
	if(a > 0) {
		std::cout << '0';
		lastPosAux = 0;
		a--;
		return true;
	}
	return false;
}
 
bool printB() {
	if(b > 0) {
		std::cout << '1';
		lastPosAux = 1;
		b--;
		return true;
	}
	return false;
}
 
int main() {
	std::cin >> a >> b >> x;
	int len = a + b;
	int x_aux = x;
	int senar = 0;
    bool firsts = false;
    bool senarX = false;

    if((/*(a >= b) && */((x%2) == 0))) {
        firsts = true;
    }
    
    if(((x%2) == 1) && ((a < x) || (b < x)) && ((a < b/2) || (b < a/2))) {
        senarX = true;
    }
	
	if(((len % 2) == 0) && (len/2) > x) {
		senar = 1;
        if(((x % 2) == 1)) {
            //std::cout << "-aux ";
            x_aux--;
        }         
	}
	
	if(b > a) {
		lastPosAux = 0;
	}
	
	for(int ii = 0; ii < len; ++ii) {
		if((ii < 2) && (senarX || firsts)) {
            if (firsts) {
                //std::cout << "FIRSTS ";
                if(lastPosAux == 0) {
                    printB();
                } else {
                    printA();
                }	
                --x_aux;
            } else if(senarX) {
                //std::cout << "SenarX ";
                if(lastPosAux == 0) {
                    printA();
                    printA();
                } else {
                    printB();
                    printB();
                }            
                ++ii;
            }
        } else if((ii%(len/x) == senar) && (x_aux > 0)) {
			--x_aux;
			//std::cout << "AUX ";
			if(lastPosAux == 0) {
				printB();
			} else {
				printA();
			}	
		} else if(lastPosAux == 0) {
			//std::cout << "ZERO ";
            if(x_aux > a) {
                printB();
                if(ii != 0) {
                    --x_aux;
                } 
            } else if(!printA()) {
				printB();		
			}
		} else if(lastPosAux == 1) {
			//std::cout << "UNO ";
            if(x_aux > b) {
                printA();
                if(ii != 0) {
                    --x_aux;
                }
            } else if(!printB()) {
				printA();		
			}	
		}
	}
	//std::cout << "x_aux: " << x_aux << std::endl;
	//std::cout << "a: " << a << " / b: " << b << std::endl;
	std::cout << std::endl;
}
