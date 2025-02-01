#include "MyStack.hpp"
#include <iostream>
//#include <stack>
#include "MyStack.hpp"
#include <vector>

// g++ .\0203StackMin.cpp MyStack.hpp -o hola

/*
  Private variable in the class. (Doesn't work because of pop).
  Or build another stack.
    Time complexity: O(n)
*/

int main()
{
    Stack<int> st;

    st.push(24);
    st.push(1);
    st.push(2);
    st.push(3);

    //for(int ii = 0; ii < v.size(); ++ii) {
    //    std::cout << v[ii] << " ";
    //}
    //std::cout << std::endl;

    std::cout << st.min() << std::endl;

    return 0;
}