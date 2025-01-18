#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

struct Node {
    int data = 0;
    Node* next = nullptr;

    Node() = default;
    Node(int val) : data(val) {}
    Node(int val,  Node* n) : data(val), next(n) {}
};

#endif