#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <thread>
#include <chrono>
#include <barrier>
#include <functional> // std::bind
#include "foo.hpp"

// g++ -std=c++20 0515CallInOrder.cpp foo.cpp -o hola

int main() {
    std::cout << "Main thread starting." << std::endl;

    Foo f;

    // The correct way to call a member function in a thread:
    // Pass the member function and the object.
    // Use std::bind to create callable objects that call the member functions on 'f'.
    std::thread t0(&Foo::first, &f);
    std::thread t1(&Foo::second, &f);
    std::thread t2(&Foo::third, &f);


    t0.join();
    t1.join();
    t2.join();

    std::cout << "Main thread waiting for other threads to finish." << std::endl;

    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    std::cout << "All threads have finished their sleeps." << std::endl;

    return 0;
}