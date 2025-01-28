#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListNode.hpp"

namespace LinkedList {
    void Insert(Node* &head, int data);
    void InsertTail(Node* &head, int data);
    void RemoveHead(Node* &head);
    void RemoveNode(Node* &previous, Node* &node);
    Node* ReverseList(Node* &n);
    Node* ReverseList2(Node* head);
    void PrintList(Node* head);
};

#endif