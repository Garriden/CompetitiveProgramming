#include "foo.hpp"
#include <iostream>

Foo::Foo() : 
    firstDone{false}, 
    secondDone{false}
{}

void Foo::first() {
    std::cout << "FIRST function called." << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    {
        std::lock_guard<std::mutex> lock(_m);
        firstDone = true;
    }
    _cv.notify_all();
    std::cout << "FIRST function finished." << std::endl;
}

void Foo::second() {
    std::unique_lock<std::mutex> lock(_m);
    _cv.wait(lock, [this]{ return firstDone; });

    std::cout << "SECOND function called." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    secondDone = true;
    _cv.notify_one();
    std::cout << "SECOND function finished." << std::endl;
}

void Foo::third() {
    std::unique_lock<std::mutex> lock(_m);
    _cv.wait(lock, [this]{ return secondDone; });
    std::cout << "THIRD function called." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Added sleep
    std::cout << "THIRD function finished." << std::endl;
}