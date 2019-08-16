// #492 Div. 2
// C 1400
// Constructive algorithms, Implementation.

#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<bool> P(100001, false);
    std::set<int> passedGeneral;
 
    std::vector<bool> firstItem(n, false);
    std::vector<int> in(n);
    for(int ii = 0; ii < n; ++ii) {
        std::cin >> in[ii];
        if(!P[in[ii]]) {
            P[in[ii]] = true;
            firstItem[ii] = true;
        }
    }

    long long res = 0;
    for(int jj = n-1; jj >= 0; --jj) {
        if(firstItem[jj]) {
            res += passedGeneral.size();
        }
        passedGeneral.insert(in[jj]);
    }

    std::cout << res << std::endl;
}
