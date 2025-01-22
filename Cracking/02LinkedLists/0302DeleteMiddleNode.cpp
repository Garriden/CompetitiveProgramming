#include <iostream>
#include "LinkedList.hpp"

// g++ .\0302DeleteMiddleNode.cpp LinkedList.cpp -o hola

/*
  Just iterate.
    Time complexity: O(n)
*/

void deleteMiddleNode(Node* n, const int k)
{
    Node* previous = n;
    n = n->next;

    int ii = 2;
    while(n != nullptr) {
        //std::cout << n->data << std::endl;
        if(ii == k) {
            LinkedList::RemoveNode(previous, n);
        }

        ++ii;
        previous = n;
        n = n->next;
    }
}

int main()
{
    Node* n = new Node{0, nullptr};

    LinkedList::Insert(n, 0);
    LinkedList::Insert(n, 1);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 3);
    LinkedList::Insert(n, 6);
    LinkedList::Insert(n, 9);
    LinkedList::Insert(n, 3);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 2);
    LinkedList::PrintList(n);

    deleteMiddleNode(n, 4);
    LinkedList::PrintList(n);

    return 0;
}