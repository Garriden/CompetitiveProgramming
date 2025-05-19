#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <thread>
#include <chrono>

// g++ -std=c++20 0315DiningPhilosophersBAD.cpp -o hola

/*
Also, the way it changes the forks vector... Could appear a Race condition.
Data inconsistency, two threads picking the same fork before any of them changes the value.
Add locks before picking a fork to avoid race conditions.

Philosopher 4 FINISHED eating 
Philosopher 0 FINISHED eating 
Philosopher 4 Pick LEFT fork  (X)
Philosopher 3 Pick RIGHT fork 
Philosopher 1 Pick LEFT fork 
Philosopher 2 Pick LEFT fork  (X)
Philosopher 3 FINISHED eating 
Philosopher 0 Pick LEFT fork  (X)
Philosopher 1 Pick RIGHT fork 
Philosopher 1 FINISHED eating 
Philosopher 1 Pick LEFT fork  (X)
Philosopher 3 Pick LEFT fork  (X)

 ! DEADLOCK !
*/

// A global mutex object.  This is what we'll use to protect our shared data.
std::mutex myMutex;

int GetRandom(int x) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return milliseconds % x;
}

void task(int id, std::vector<bool> &forks) {
    std::cout << "Philosopher " << id << " starting..." << std::endl;
    bool left = false;
    bool right = false;
    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(GetRandom(10)*100));
        if(!left) {
            int leftPosition = id - 1;
            if(leftPosition == -1) {
                leftPosition = forks.size() - 1;
            }

            myMutex.lock();
            if(!forks[leftPosition]) { // If fork available, pick a fork.
                std::cout << "Philosopher " << id << " Pick LEFT fork " << std::endl;
                left = true;
                forks[leftPosition] = true;
            }
            myMutex.unlock();

        } else if(!right) {
            int rightPosition = id + 1;
            if(rightPosition == forks.size()) {
                rightPosition = 0;
            }

            myMutex.lock();
            if(!forks[rightPosition]) { // If fork available, pick a fork.
                std::cout << "Philosopher " << id << " Pick RIGHT fork " << std::endl;
                right = true;
                forks[rightPosition] = true;
            }
            myMutex.unlock();

        } else {
            int leftPosition = id - 1;
            if(leftPosition == -1) {
                leftPosition = forks.size() - 1;
            }
            int rightPosition = id + 1;
            if(rightPosition == forks.size()) {
                rightPosition = 0;
            }

            myMutex.lock();
            left = false;
            forks[leftPosition] = false;
            right = false;
            forks[rightPosition] = false;
            myMutex.unlock();

            std::cout << "Philosopher " << id << " FINISHED eating " << std::endl;
        }
    }
}

int main() {
    std::cout << "Main thread starting." << std::endl;

    std::vector<bool> forks(5, false);

    std::thread t0(task, 0, std::ref(forks));
    std::thread t1(task, 1, std::ref(forks));
    std::thread t2(task, 2, std::ref(forks));
    std::thread t3(task, 3, std::ref(forks));
    std::thread t4(task, 4, std::ref(forks));

    std::cout << "Main thread waiting for other threads to finish." << std::endl;

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "All threads have finished their sleeps." << std::endl;

    return 0;
}