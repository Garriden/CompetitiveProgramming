#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 BubbleSort.cpp -o hola

void BubbleSort(std::vector<int> &v) {
    int n = v.size();

    for(int ii = 0; ii < n - 1; ++ii) {
        bool swapped = false;
        for(int jj = 0; jj < n - 1 - ii; ++jj) {
            if(v[jj] > v[jj+1]) { // swap.
                swapped = true;
                int aux = v[jj];
                v[jj] = v[jj+1];
                v[jj+1] = aux;
            }
        }

        if(!swapped) { // already ordered.
            return;
        }
    }

}

int main()
{
    int n = 10;
    std::vector<int> v = {24, 68, 2, 69, 54, 7, 28, 18, 10, 66};

    BubbleSort(v);

    for(int ii = 0; ii < n; ++ii) {
        std::cout << v[ii] << " ";
    }
    std::cout << std::endl;

    return 0;
}