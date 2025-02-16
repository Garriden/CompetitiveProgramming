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

void Enqueue(const std::string& animalName, const std::string& animal)
{

}

int main()
{
    Enqueue("Marrameu",     "cat");
    Enqueue("Mixa",         "cat");
    Enqueue("Orelles",      "dogo");
    Enqueue("ElRufas",      "cat");


    while (!queue.empty()) {
        //std::cout << queue.front() << " ";
        //queue.pop();
    }
    std::cout << std::endl;
    
    return 0;
}