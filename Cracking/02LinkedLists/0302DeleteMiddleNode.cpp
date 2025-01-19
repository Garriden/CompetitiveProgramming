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
            LinkedList::removeNode(previous, n);
        }

        ++ii;
        previous = n;
        n = n->next;
    }
}

int main()
{
    Node* n = new Node{0, nullptr};

    LinkedList::insert(n, 0);
    LinkedList::insert(n, 1);
    LinkedList::insert(n, 2);
    LinkedList::insert(n, 3);
    LinkedList::insert(n, 6);
    LinkedList::insert(n, 9);
    LinkedList::insert(n, 3);
    LinkedList::insert(n, 2);
    LinkedList::insert(n, 2);
    LinkedList::printList(n);

    deleteMiddleNode(n, 4);
    LinkedList::printList(n);

    return 0;
}