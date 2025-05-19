#include <iostream>
#include <cstdint>
#include <string.h>
#include <thread>
#include <chrono>

// g++ -std=c++20 CreateThreads.cpp -o hola

void task(int id, int sleep_duration_ms) {
    std::cout << "Thread " << id << " starting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration_ms));
    std::cout << "Thread " << id << " woke up after " << sleep_duration_ms << " milliseconds." << std::endl;
}

int main() {
    std::cout << "Main thread starting." << std::endl;

    std::thread t1(task, 1, 5000); // Thread 1 will sleep for 2 seconds
    std::thread t2(task, 2, 1000); // Thread 2 will sleep for 1 second
    std::thread t3(task, 3, 3000); // Thread 3 will sleep for 3 seconds

    std::cout << "Main thread waiting for other threads to finish sleeping." << std::endl;

    t1.join();
    t2.join();
    t3.join();

    std::cout << "All threads have finished their sleeps." << std::endl;

    return 0;
}