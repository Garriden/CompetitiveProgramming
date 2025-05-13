#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 SelectionSort.cpp -o hola

void SelectionSort(std::vector<int> &v) {
    int n = v.size();

    for(int ii = 0; ii < n - 1; ++ii) {
        //bool swapped = false; // Doesnt work because max is always initializated at zero.
        int maxPosition = 0;
        for(int jj = 0; jj < n - ii; ++jj) {
            if(v[jj] > v[maxPosition]) {
                maxPosition = jj;
            }
        }

        // Swap.
        int aux = v[n-1-ii];
        v[n-1-ii] = v[maxPosition];
        v[maxPosition] = aux;

        //for(int ii = 0; ii < n; ++ii) {
        //    std::cout << v[ii] << " ";
        //} std::cout << std::endl;
    }

}

int main()
{
    int n = 10;
    std::vector<int> v = {24, 68, 2, 69, 54, 7, 28, 18, 10, 66};

    SelectionSort(v);

    for(int ii = 0; ii < n; ++ii) {
        std::cout << v[ii] << " ";
    } std::cout << std::endl;

    return 0;
}