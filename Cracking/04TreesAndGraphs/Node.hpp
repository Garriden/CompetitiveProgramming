#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <queue>

class Node {
public:
    Node();
    Node(int val);

    static int GetMaxLevelBFS(Node* n);
    static void PrintBinaryTree(Node* n);

    int value;
    Node* left;
    Node* right;
    Node* parent;
};


#endif