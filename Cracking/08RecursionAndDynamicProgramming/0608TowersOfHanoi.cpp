#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>

// g++ -std=c++20 0608TowersOfHanoi.cpp -o hola


void TowerOfHanoi(int n, char source, char target, char auxiliary) {
    if(n > 0) {
        TowerOfHanoi(n - 1, source, auxiliary, target);
        std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
        TowerOfHanoi(n - 1, auxiliary, target, source);
    }
}


int main()
{
    int numDisks = 3;

    TowerOfHanoi(numDisks, 'A', 'C', 'B');


    return 0;
}