#include <iostream>
#include "LinkedList.hpp"

// g++ .\0402Partition.cpp LinkedList.cpp -o hola

/*
  Just iterate.
    Time complexity: O(n)
*/

void Part(Node* head, int x, Node* &n1Head, Node* &n2Head) {
    Node* n1Runner = nullptr;
    Node* n2Runner = nullptr;

    //  nextNode
    //           
    // head -/> next
    //   \->nullptr

    // n1Runner is head
    // n2Runner is head

    // head is nextNode

    //So, head single node migrates to new list. 
    // Then, to continue the script, head becames his next node.

    while(head != nullptr) {
        Node* nextNode = head->next; // Important: Store next before modifying head->next
        head->next = nullptr; // Important: Disconnect the node

        if(head->data < x) {
            if (n1Head == nullptr) {
                n1Head = head;
                n1Runner = head;
            } else {
                n1Runner->next = head;
                n1Runner = head;
            }
        } else {
            if (n2Head == nullptr) {
                n2Head = head;
                n2Runner = head;
            } else {
                n2Runner->next = head;
                n2Runner = head;
            }
        }
        head = nextNode;
    }
}

int main()
{
    Node* n = new Node(24, nullptr);

    LinkedList::insert(n, 10);
    LinkedList::insert(n, 11);
    LinkedList::insert(n, 4);
    LinkedList::insert(n, 12);
    LinkedList::insert(n, 13);
    LinkedList::insert(n, 2);
    LinkedList::insert(n, 1);
    LinkedList::insert(n, 0);
    LinkedList::insert(n, 5);
    LinkedList::printList(n);

    Node* n1 = nullptr;
    Node* n2 = nullptr;
    Part(n,6,n1,n2);

    LinkedList::printList(n1);
    LinkedList::printList(n2);

    return 0;
}