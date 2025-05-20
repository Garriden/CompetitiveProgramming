#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <thread>
#include <chrono>
#include "foo.hpp"

// g++ -std=c++20 0715FizzBuzzSequential.cpp -o hola

// minimum: 60us

int main() {
    int n = 1000;

    auto start = std::chrono::high_resolution_clock::now();
    for(int ii = 0; ii < n; ++ii) {
        if(ii % 3 == 0 && ii % 5 == 0) {
            std::cout << ii << ": FizzBuzz" << std::endl;
        } else if(ii % 3 == 0) {
            std::cout << ii << ": Fizz" << std::endl;
        } else if(ii % 5 == 0) {
            std::cout << ii << ": Buzz" << std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken by the code: " << duration.count() << "ms" << std::endl;

    return 0;
}