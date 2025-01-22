#include <iostream>
#include <math.h>
#include "LinkedList.hpp"

// g++ .\0502SumLists.cpp LinkedList.cpp -o hola

/*
  Just iterate.
    Time complexity: O(n)
    - Convert list to a number using increment * 10.
    - Convert number to a list using %10, /10.
    // 7->1->6 => 617
    // 5->9->2 => 295
    // 617 + 592 = 912
    // 2->1->9
*/

int getLengthList(Node* n)
{
    Node* nAux = n;
    int count = 0;

    while(n != nullptr) {
        ++count;
        n = n->next;
    }

    //std::cout << "len: " << count << std::endl;
    return count;
}

int getLength(const int x)
{
    int aux = x;
    int count = 0;

    while(aux > 0) {
        aux /= 10;
        ++count;
    }

    //std::cout << "len: " << count << std::endl;
    return count;
}

Node* SumLists(Node* &n1Head, Node* &n2Head)
{
    int number1 = 0;
    int number2 = 0;

    int len = getLengthList(n1Head);
    --len;
    // 6->1->7 => 617
    while(n1Head != nullptr) {
        int aux = n1Head->data*(pow(10,len));
        number1 += aux;
        --len;
        n1Head = n1Head->next;
    }

    // 2->9->5 => 295
    len = getLengthList(n2Head);
    --len;
    // 6->1->7 => 617
    while(n2Head != nullptr) {
        int aux = n2Head->data*(pow(10,len));
        number2 += aux;
        --len;
        n2Head = n2Head->next;
    }

    // 617 + 295 = 912
    std::cout << "number1: " << number1 << "  number2: " << number2 << std::endl;
    int number = number1 + number2;

    // 2->1->9
    len = getLength(number);
    Node* ret = new Node(number%10);
    number /= 10;
    while(number > 0) {
        LinkedList::Insert(ret, number%10);
        number /= 10;
    }

    return ret;
}

Node* SumListsReverse(Node* &n1Head, Node* &n2Head)
{
    int it = 1;
    int number1 = 0;
    int number2 = 0;

    // 7->1->6 => 617
    while(n1Head != nullptr) {
        number1 += n1Head->data * it;
        it *= 10;
        n1Head = n1Head->next;
    }

    // 5->9->2 => 295
    it = 1;
    while(n2Head != nullptr) {
        number2 += n2Head->data * it;
        it *= 10;
        n2Head = n2Head->next;
    }

    // 617 + 295 = 912
    std::cout << "number1: " << number1 << "  number2: " << number2 << std::endl;
    int number = number1 + number2;

    // 2->1->9
    int len = getLength(number);
    --len;
    Node* ret = new Node(number/(pow(10,len)));
    number = number%(int)(pow(10,len));
    --len;
    while(number > 0) {
        LinkedList::Insert(ret, number/(pow(10,len)));
        number = number%(int)(pow(10,len));
        --len;
    }

    return ret;
}

int main()
{
    Node* n1 = new Node(7, nullptr);
    LinkedList::Insert(n1, 1);
    LinkedList::Insert(n1, 6);

    Node* n2 = new Node(5, nullptr);
    LinkedList::Insert(n2, 9);
    LinkedList::Insert(n2, 2);

    LinkedList::PrintList(SumLists(n1,n2));

    Node* n3 = new Node(6, nullptr);
    LinkedList::Insert(n3, 1);
    LinkedList::Insert(n3, 7);

    Node* n4 = new Node(2, nullptr);
    LinkedList::Insert(n4, 9);
    LinkedList::Insert(n4, 5);

    LinkedList::PrintList(SumListsReverse(n3,n4));

    return 0;
}