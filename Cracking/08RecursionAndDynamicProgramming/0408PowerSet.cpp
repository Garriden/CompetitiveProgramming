#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>

// g++ -std=c++20 0408PowerSet.cpp -o hola

// Memorization.



std::vector<std::vector<std::vector<int> > > BuildSubset(const std::vector<int> v)
{
    int n = v.size();
    std::vector<std::vector<std::vector<int> > > res(n + 1); // for every n, make all possible subsets.

    res[0].push_back({});
    for(int ii = 1; ii <= n; ++ii) {
        std::vector<std::vector<int> > combinationsN;
        std::vector<int> aux;
        
        // last combination (a1a2a3)
        for(int jj = 1; jj <= ii; ++jj) {
            aux.push_back(jj);
        }
        // print combinationsN.
        //for(int jj = 0; jj < aux.size(); ++jj) {
        //        std::cout << aux[jj] << " ";
        //} std::cout << std::endl;

        combinationsN.push_back(aux);
        aux.clear();
        // intermediate combinations (a1a3, a2a3)
        // NOT WORKING WELL when n > 3
        for(int jj = 1; jj < ii; ++jj) {
            aux.push_back(jj);
            aux.push_back(ii);
            combinationsN.push_back(aux);
            aux.clear();
        }

        // print combinationsN.
        //for(int jj = 0; jj < combinationsN.size(); ++jj) {
        //    for(int kk = 0; kk < combinationsN[jj].size(); ++kk) {
        //        std::cout << combinationsN[jj][kk] << " ";
        //    }
        //} std::cout << std::endl;

        // Unite last combination with new one.
        //std::vector<std::vector<int> > lastCombination = res[ii - 1];
        res[ii] = res[ii - 1];
        for(int jj = 0; jj < combinationsN.size(); ++jj) {
            res[ii].push_back(combinationsN[jj]);
        }

        // print new combination n.
        for(int jj = 0; jj < res[ii].size(); ++jj) {
            for(int kk = 0; kk < res[ii][jj].size(); ++kk) {
                std::cout << res[ii][jj][kk] << " ";
            }
            std::cout << ", ";
        } std::cout << std::endl;
    }

    return res;
}

int main()
{
    int n = 5;
    std::vector<int> v{1, 2, 3, 4, 5};

    BuildSubset(v);



    return 0;
}