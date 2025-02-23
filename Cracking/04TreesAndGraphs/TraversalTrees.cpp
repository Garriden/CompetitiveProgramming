#include <iostream>
#include "Node.hpp"

// g++ TraversalTrees.cpp Node.cpp -o hola

// 4 2 5 1 6 3 7
void inorder(Node* n) // Left + root + Right
{
    if(n != nullptr) {
        inorder(n->left);
        std::cout << n->value << std::endl;
        inorder(n->right);
    }
}

// 1 4 2 5 6 3 7
void preorder(Node* n) // root + left + right
{
    if(n != nullptr) {
        std::cout << n->value << std::endl;
        inorder(n->left);
        inorder(n->right);
    }
}

// 4 2 5 6 3 7 1
void postorder(Node* n) // Left + Right + root
{
    if(n != nullptr) {
        inorder(n->left);
        inorder(n->right);
        std::cout << n->value << std::endl;
    }
}

int main()
{
    // Build a tree.
    Node* n = new Node(1);
    n->left = new Node(2);
    n->right = new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left = new Node(6);
    n->right->right = new Node(7);

    postorder(n);

    return 0;
}