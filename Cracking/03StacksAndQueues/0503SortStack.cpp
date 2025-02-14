#include <stack>
#include <iostream>

// g++ .\0503SortStack.cpp -o hola

/*
    Time complexity: O(n)
*/

void SortStack(std::stack<int>& st)
{
    std::stack<int> stack1;
    std::stack<int> stack2;

    //find bigger one, stack
    // Time complexity O(n^2)

    //Some sorting algorithm?

}

int main()
{
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    SortStack(st);

    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
    
    return 0;
}