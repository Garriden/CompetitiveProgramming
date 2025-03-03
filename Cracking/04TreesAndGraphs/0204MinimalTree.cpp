#include <iostream>

#include "Node.hpp"

// g++ .\0204MinimalTree.cpp Node.cpp -o hola

/*
    Given a sorted (increasing order) array, create binary search tree with minimal weight.
     (lext < n < right)
*/


int main()
{
    // Build a min heap.
    Node* n = new Node(4);
    n->parent = nullptr;

    n->left = new Node(50);
    n->left->parent = n;

    n->right = new Node(7);
    n->right->parent = n;

    n->left->left = new Node(55);
    n->left->left->parent = n->left;

    n->left->right = new Node(99);
    n->left->right->parent = n->left;

    n->right->left = new Node(87);
    n->right->left->parent = n->right;
    //n->right->right = new Node(88);

    return 0;
}