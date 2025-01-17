#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListNode.hpp"

namespace LinkedList {
    void insert(Node* &head, int data);
    void removeHead(Node* &head);
    void removeNode(Node* &previous, Node* &node);
    void printList(Node* head);
};

#endif