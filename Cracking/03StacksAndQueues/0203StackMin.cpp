#include "MyStack.hpp"
#include <iostream>
//#include <stack>
#include "MyStack.hpp"
#include <vector>

// g++ .\0203StackMin.cpp MyStack.hpp -o hola

/*
  Private variable in the class. (Doesn't work because of pop).
  Or build another data structure.
    Time complexity: O(n)
*/

int main()
{
    Stack<int> st;

    st.push(24);
    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();
    st.pop();
    st.pop();
    st.push(12);

    std::cout << st.min() << std::endl;

    return 0;
}