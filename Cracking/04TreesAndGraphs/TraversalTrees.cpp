#include <iostream>
#include "Node.hpp"

// g++ TraversalTrees.cpp Node.cpp -o hola

// 2 1 3
void inorder(Node* n)
{
    if(n != nullptr) {
        inorder(n->left);
        std::cout << n->vaule << std::endl;
        inorder(n->right);
    }
}

int main()
{
    // Build a tree.
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right = new Node(3);

    inorder(n);

    return 0;
}