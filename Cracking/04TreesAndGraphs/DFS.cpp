#include <iostream>
#include "Node.hpp"
#include <stack>

// g++ DFS.cpp Node.cpp -o hola

int maxLevel = 0;

// 4 2 5 6 3 7 1
void DFS(Node* n, int level)
{
    std::cout << "Node: " << n->value << "  / level: " << level << std::endl;

    if(level > maxLevel) {
        maxLevel = level;
    }

    if(n->left != nullptr) {
        DFS(n->left, level+1);
    }
    if(n->right != nullptr) {
        DFS(n->right, level+1);
    }
}

int DFSIterative(Node* n) {
    int maxLevel = 1;
    int level = 1;
    std::stack<Node *> st;
    std::stack<int> levels;
    st.push(n);
    levels.push(1);

    while(!st.empty()) {
        std::cout << "Node: " << n->value << "  / level: " << level << std::endl;
        
        if(level > maxLevel) {
            maxLevel = level;
        }

        if(n->right != nullptr) {
            st.push(n->right);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->right->value << "  / level: " << level+1 << std::endl;
        }

        if(n->left != nullptr) {
            st.push(n->left);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->left->value << "  / level: " << level+1 << std::endl;
        }

        n = st.top(); 
        st.pop();
        level = levels.top();
        levels.pop();
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
    maxLevel = DFSIterative(n);

    std::cout << "maxLevel: " << maxLevel << std::endl;

    return 0;
}