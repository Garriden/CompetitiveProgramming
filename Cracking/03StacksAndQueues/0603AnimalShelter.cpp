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
    std::string ret = queue[0].second;
    //std::cout  << std::endl;
    queue.erase(queue.begin()->first);
    return ret;
}

int main()
{
    Enqueue("cat", "Marrameu");
    Enqueue("cat", "Mixa");
    Enqueue("dog", "Orelles");
    Enqueue("cat", "ElRufas");


    //while (!queue.empty()) {
        //std::cout << queue.front() << " ";
        //queue.pop();
    //}
    

    for(auto it : queue) {
        std::cout << it.first << " " << it.second.first << " " << it.second.second << std::endl;
    } std::cout << std::endl;

    DequeueAny();
    DequeueAny();
    DequeueAny();

    for(auto it : queue) {
        std::cout << it.first << " " << it.second.first << " " << it.second.second << std::endl;
    } std::cout << std::endl;

    return 0;
}