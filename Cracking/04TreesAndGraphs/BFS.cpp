#include <iostream>
#include "Node.hpp"
#include <queue>

// g++ BFS.cpp Node.cpp -o hola

int maxLevel = 0;

int BFSIterative(Node* n) {
    int maxLevel = 1;
    int level = 1;
    std::queue<Node *> qu;
    std::queue<int> levels;
    qu.push(n);
    levels.push(1);

    while(!qu.empty()) {
        std::cout << "Node: " << n->value << "  / level: " << level << std::endl;
        
        if(level > maxLevel) {
            maxLevel = level;
        }

        if(n->left != nullptr) {
            qu.push(n->left);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->left->value << "  / level: " << level+1 << std::endl;
        }

        if(n->right != nullptr) {
            qu.push(n->right);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->right->value << "  / level: " << level+1 << std::endl;
        }

        
        qu.pop();
        n = qu.front(); 

        levels.pop();
        level = levels.front();
    }
    
    return maxLevel;
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
    //n->right->right = new Node(7);

    //DFS(n, 1);
    maxLevel = BFSIterative(n);

    std::cout << "maxLevel: " << maxLevel << std::endl;

    return 0;
}