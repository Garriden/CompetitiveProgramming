#include "MyStack.hpp"
#include <iostream>
#include <stack>
#include <vector>

// g++ .\0103ThreeInOne.cpp MyStack.hpp -o hola

/*
  Just iterate. 3 or 4 pointers.
    Time complexity: O(n)
*/

std::vector<int> v(100, 0);
int stack1Top = 0;
int stack2Top = v.size() - 1;
int stack3Top = 30; // Posible improvement, be in the end of stack1

void InsertStack1(int x)
{
    v[stack1Top++] = x;
}

void InsertStack2(int x)
{
    v[stack2Top--] = x;
}

void InsertStack3(int x)
{
    v[stack3Top++] = x;
}

void DeleteStack1() { v[--stack1Top] = 0;}
void DeleteStack2() { v[++stack2Top] = 0;}
void DeleteStack3() { v[--stack3Top] = 0;}

int main()
{
    InsertStack1(24);
    InsertStack1(25);
    InsertStack1(26);

    InsertStack2(81);
    InsertStack2(82);
    InsertStack2(83);
    InsertStack2(84);

    InsertStack3(1);
    InsertStack3(2);

    InsertStack1(2);
    InsertStack3(3);
    InsertStack2(8);

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    }
    std::cout << std::endl;

    DeleteStack1();
    DeleteStack3();
    DeleteStack2();

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    }
    std::cout << std::endl;

    InsertStack1(2);
    InsertStack3(3);
    InsertStack2(8);

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    }
    std::cout << std::endl;

    return 0;
}