#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 1016LivingPeople.cpp -o hola

// delta vector, make a vector on which element is every year.
//  if BirthYear, v[year]++
//  if DeadYear,  v[year]--
// iterate trough the vector and keep the max.
// O(n)

int main()
{
    std::vector<std::pair<int,int> > v = { {1900,2000}, {1925,1968}, {1925,1968}, {1912,1978}, {1965,1995} };
    /*
    std::map<int, int> yearFreq;

    for(int ii = 0; ii < v.size(); ++ii) {
        int jj = v[ii].first;
        while(jj <= v[ii].second) {
            yearFreq[jj]++;
            ++jj;
        }
    }

    int maxPersons = 0;
    int maxPersonsYear = 0;
    for(const auto& elem : yearFreq) {
        //std::cout << elem.first << ", persons: " << elem.second << std::endl;
        if(elem.second > maxPersons) {
            maxPersons = elem.second;
            maxPersonsYear = elem.first;
        }
    }

    std::cout << maxPersonsYear << ", persons: " << maxPersons << std::endl;
    */

    std::vector<int> delta(101, 0);
    for(int ii = 0; ii < v.size(); ++ii) {
        delta[v[ii].first - 1900]++;
        delta[v[ii].second - 1900]--;
    }

    int maxPersons = 0;
    int maxYear = 0;
    int cont = 0;
    for(int ii = 0; ii < delta.size(); ++ii) {
        cont += delta[ii];
        if(cont > maxPersons) {
            maxPersons = cont;
            maxYear = 1900 + ii;
        }
    }

    std::cout << maxYear << ", persons: " << maxPersons << std::endl;

    return 0;
}