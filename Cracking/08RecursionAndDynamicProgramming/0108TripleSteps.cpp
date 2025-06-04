#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>

// g++ -std=c++20 0108TripleSteps.cpp -o hola

int steps(int n) {
    if(n < 0) {
        return 0;
    } else if(n == 0) {
        return 1;
    } else {
        return steps(n - 1) + steps(n - 2) + steps(n - 3);
    }
}

int stepsMemorization(int n, std::vector<int> memo) {
    if(n < 0) {
        return 0;
    } else if(n == 0) {
        return 1;
    } else if(memo[n] > -1) {
        return memo[n];
    } else {
        memo[n] = stepsMemorization(n - 1, memo) + 
                  stepsMemorization(n - 2, memo) + 
                  stepsMemorization(n - 3, memo);
    }

    return memo[n];
}

int main() {

    steps(5);

    std::vector<int> memo(5 + 1, -1);

    std::cout << "Total steps: " << stepsMemorization(5, memo) << std::endl;

    return 0;
}