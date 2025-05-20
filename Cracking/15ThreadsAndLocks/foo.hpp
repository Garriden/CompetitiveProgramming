#include <mutex>
#include <condition_variable>
#include <functional> // std::bind

class Foo {
public:
    Foo();

    void first();
    void second();
    void third();

private:
    std::mutex _m;
    std::condition_variable _cv;
    bool firstDone = false;
    bool secondDone = false;
};