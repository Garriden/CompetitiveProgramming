#include <queue>
#include <map>
#include <string>
#include <iostream>

// g++ .\0603AnimalShelter.cpp -o hola

/*
    Enqueue
    DequeueAny
    DequeueCat
    DequeueDog

    // Two queues. How to know dog or cat order? Additional datastructure? bitset?

    // or put a "queue" of pair <name, animal>. But need to implement a s a list from scratch.
    //  it maintanis the order, but need to iterate the "list" to see the next cat without modifying the front dogs.

    // Store it in a map! Key = index, value = name. (Two maps, or the value could be a pair of <name, animal> ).
*/

std::map<int, std::pair<std::string,std::string> > queue;

static int index = 0;

void Enqueue(const std::string& animal, const std::string& animalName)
{
    queue[index++] = {animal, animalName};
}

std::string DequeueAny()
{
    std::string ret = queue.begin()->second.second;
    queue.erase(queue.begin());
    return ret;
}

std::string DequeueCat()
{
    for(const auto& elem : queue) {
        if(elem.second.first == "cat") { // find first cat.
            queue.erase(elem.first);
            return elem.second.second;
        }
    }

    return "Not more cats available. I killed... I'm kidding, all of them have a warm house.";
}


std::string DequeueDog()
{
    for(const auto& elem : queue) {
        if(elem.second.first == "dog") { // find first fogo.
            queue.erase(elem.first);
            return elem.second.second;
        }
    }

    return "No more dogo.";
}

int main()
{
    Enqueue("cat", "Marrameu");
    Enqueue("cat", "Mixa");
    Enqueue("dog", "Orelles");
    Enqueue("cat", "ElRufas");

    std::cout << DequeueAny() << std::endl;
    std::cout << DequeueAny() << std::endl;
    std::cout << DequeueAny() << std::endl;

    std::cout << std::endl;

    Enqueue("cat", "AAA");
    Enqueue("cat", "BBB");
    Enqueue("dog", "ZZZZ");
    Enqueue("cat", "CCC");
    Enqueue("dog", "YYYYY");
    Enqueue("cat", "DDD");
    Enqueue("dog", "XXX");

    for(auto it : queue) {
        std::cout << it.first << " " << it.second.first << " " << it.second.second << std::endl;
    } std::cout << std::endl;


    std::cout << DequeueCat() << std::endl;
    std::cout << DequeueCat() << std::endl;

    std::cout << std::endl;

    std::cout << DequeueDog() << std::endl;
    std::cout << DequeueDog() << std::endl;
    std::cout << DequeueDog() << std::endl;
    std::cout << DequeueDog() << std::endl;

    return 0;
}