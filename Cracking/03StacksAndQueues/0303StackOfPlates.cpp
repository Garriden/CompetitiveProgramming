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
    stacks.top();
    stacks.push(1);
    stacks.push(2);
    stacks.push(3);

    //st.pop();
    //st.pop();
    //st.pop();
    //st.push(12);

    //std::cout << st.min() << std::endl;

    return 0;
}