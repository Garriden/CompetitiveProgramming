#include "MyQueueFrom2Stacks.hpp"
#include <iostream>

// g++ .\0403QueueViaStacks.cpp MyQueueFrom2Stacks.hpp -o hola

/*
    Time complexity: O(n)
*/

int main()
{
    Queue<int> stacks;

    stacks.push(24);
    std::cout << stacks.front() << std::endl;
    
    stacks.push(1);
    std::cout << stacks.front() << std::endl;

    stacks.push(2);
    std::cout << stacks.front() << std::endl;
    
    stacks.push(4);
    std::cout << stacks.front() << std::endl;
    stacks.push(5);
    std::cout << stacks.front() << std::endl;
    stacks.push(6);
    std::cout << stacks.front() << std::endl;
    stacks.push(7);
    std::cout << stacks.front() << std::endl;
    std::cout << "Back: " << stacks.back() << std::endl;

    stacks.pop();
    std::cout << stacks.front() << std::endl;
    stacks.pop();
    std::cout << stacks.front() << std::endl;
    stacks.pop();
    std::cout << stacks.front() << std::endl;
    stacks.pop();
    std::cout << stacks.front() << std::endl;
    stacks.pop();
    std::cout << stacks.front() << std::endl;
    std::cout << "Back: " << stacks.back() << std::endl;

    stacks.push(8);
    std::cout << stacks.front() << std::endl;
    
    return 0;
}