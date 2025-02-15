#include <stack>
#include <iostream>

// g++ .\0503SortStack.cpp -o hola

/*
    Find bigger one, stack (but needs three stacks).

    Some sorting algorithm? (Quick sort or merge sort but requieres infinite stacks or additional data structure).

    Sorting algorithm. Pick one element
    Time complexity O(n^2). Space complexity O(n)
*/

void SortStack(std::stack<int>& st)
{
    std::stack<int> stack2;

    while(!st.empty()) {
        int value = st.top();
        st.pop();
        while(!stack2.empty() && value > stack2.top()) {
            int aux = stack2.top();
            stack2.pop();
            st.push(aux);
        }

        if(stack2.empty() || value <= stack2.top()) {
            stack2.push(value);
        }
    }

    st = stack2;
}

int main()
{
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // 4 3 2 1
    SortStack(st);
    // 1 2 3 4

    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
    
    return 0;
}