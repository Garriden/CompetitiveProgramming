#include "MyStack.hpp"
#include <iostream>
//#include <stack>
#include "MyStack.hpp"
#include <vector>

// g++ .\0303StackOfPlates.cpp MyStack.hpp -o hola

/*
  
    Time complexity: O(n)
*/

int main()
{
    SetOfStackS<int> stacks(3);

    stacks.push(24);
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    
    stacks.push(1);
    std::cout << stacks.top() << std::endl;

  
    stacks.push(2);
    //stacks.push(3);
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    std::cout << stacks.top() << std::endl;
    
   stacks.push(4);
   std::cout << stacks.top() << std::endl;
   stacks.push(5);
   std::cout << stacks.top() << std::endl;
   stacks.push(6);
   std::cout << stacks.top() << std::endl;
   stacks.push(7);
   std::cout << stacks.top() << std::endl;

    stacks.pop();
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    std::cout << stacks.top() << std::endl;
    stacks.pop();
    std::cout << stacks.top() << std::endl;

    return 0;
}