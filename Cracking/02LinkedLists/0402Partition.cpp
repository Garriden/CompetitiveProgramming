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

    LinkedList::Insert(n, 10);
    LinkedList::Insert(n, 11);
    LinkedList::Insert(n, 4);
    LinkedList::Insert(n, 12);
    LinkedList::Insert(n, 13);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 1);
    LinkedList::Insert(n, 0);
    LinkedList::Insert(n, 5);
    LinkedList::PrintList(n);

    Node* n1 = nullptr;
    Node* n2 = nullptr;
    Part(n,6,n1,n2);

    LinkedList::PrintList(n1);
    LinkedList::PrintList(n2);

    return 0;
}