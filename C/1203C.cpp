// #579 Div. 3
// C 1300
// Implementation, Math

#include <bits/stdc++.h>

int main() {
    long long a, x; 
    long long g = 0;
    std::cin >> a;
 
    for(long long ii = 0; ii < a; ++ii) {
        std::cin >> x;
        g = std::__gcd(g, x);
    }
    
    long long ii;
    long long res = 0;
    for(ii = 1ll; ii*ii <= g; ++ii) {
       if((g % ii) == 0) {
           ++res;
           //Mike
            if (ii != g / ii) {
				++res;
            }
       }
       
    }
    
    std::cout << res << std::endl;
}
