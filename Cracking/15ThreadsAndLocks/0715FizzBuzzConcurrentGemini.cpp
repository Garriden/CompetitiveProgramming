#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

// Actually, same.
// minimum: 60ms

// g++ -std=c++20 0715FizzBuzzConcurrentGemini.cpp -o hola

constexpr int n = 1000;

std::mutex cout_mutex;
std::atomic<int> current_number(1);

void fizzBuzzWorker(int num_threads) {
    while (current_number <= n) {
        int num = current_number.load();
        if (num > n) break; // Ensure we don't go beyond n

        if (num % 3 == 0 && num % 5 == 0) {
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << num << ": FizzBuzz" << std::endl;
            }
            current_number.fetch_add(1, std::memory_order_relaxed);
        } else if (num % 3 == 0) {
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << num << ": Fizz" << std::endl;
            }
            current_number.fetch_add(1, std::memory_order_relaxed);
        } else if (num % 5 == 0) {
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << num << ": Buzz" << std::endl;
            }
            current_number.fetch_add(1, std::memory_order_relaxed);
        } else {
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
            }
            current_number.fetch_add(1, std::memory_order_relaxed);
        }
        // This is a hint to the operating system to allow other threads to run.
        // It can help in preventing one thread from monopolizing the CPU.
        std::this_thread::yield();
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    //int num_threads = std::thread::hardware_concurrency();
    int num_threads = 3;
    std::cout << "Using " << num_threads << " threads." << std::endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(fizzBuzzWorker, num_threads);
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\nTime taken by the concurrent code: " << duration.count() << " ms" << std::endl;

    return 0;
}