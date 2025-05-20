#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <thread>
#include <chrono>
#include <barrier>

// g++ -std=c++20 0715FizzBuzzConcurrentBAD.cpp -o hola

// minimum: 78ms

constexpr int n = 1000;

std::barrier myBarrier(3);

void FizzBuzz()
{
    for(int ii = 0; ii < n; ++ii) {
        if(ii % 3 == 0 && ii % 5 == 0) {
            std::cout << ii << ": FizzBuzz" << std::endl;
        }
    }
    myBarrier.arrive_and_wait();
}

void Fizz()
{
    for(int ii = 0; ii < n; ++ii) {
        if(ii % 3 == 0) {
            std::cout << ii << ": Fizz" << std::endl;
        }
    }
    myBarrier.arrive_and_wait();
}

void Buzz()
{
    for(int ii = 0; ii < n; ++ii) {
        if(ii % 5 == 0) {
            std::cout << ii << ": Buzz" << std::endl;
        }
    }
    myBarrier.arrive_and_wait();
}

int main() {
    

    auto start = std::chrono::high_resolution_clock::now();

    std::thread t0(FizzBuzz);
    std::thread t1(Fizz);
    std::thread t2(Buzz);

    t0.join();
    t1.join();
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken by the code: " << duration.count() << "ms" << std::endl;

    return 0;
}