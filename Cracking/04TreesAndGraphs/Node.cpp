
#include "Node.hpp"

Node::Node() : value{0}, left{nullptr}, right{nullptr} {}

Node::Node(int val) : value{val}, left{nullptr}, right{nullptr} {}

int Node::GetMaxLevelBFS(Node* n) {
    int maxLevel = 1;
    int level = 1;
    std::queue<Node *> qu;
    std::queue<int> levels;
    qu.push(n);
    levels.push(1);

    while(!qu.empty()) {
        //std::cout << "Node: " << n->value << "  / level: " << level << std::endl;
        
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

//        1
//      /    
//    2        3
void Node::PrintBinaryTree(Node* n)
{
    int maxLevel = Node::GetMaxLevelBFS(n);
    int level = 1;
    int levelBefore = 1;
    std::queue<Node *> qu;
    std::queue<int> levels;
    qu.push(n);
    levels.push(1);

    while(!qu.empty()) {
        //std::cout << "Node: " << n->value << "  / level: " << level  << "  / levelBefore: " << levelBefore << std::endl;

        if(levelBefore != level) {
            std:: cout << std:: endl;

            //for(int ii = level-1; ii < maxLevel; ++ii) {
            //    std::cout << "    ";
            //} std::cout << "  /     | ";
            std:: cout << std:: endl;
        }

        for(int ii = level; ii <= maxLevel; ++ii) {
            std::cout << "    ";
        } std::cout << n->value;

        if(n->left != nullptr) {
            qu.push(n->left);
            levels.push(level+1);
        }

        if(n->right != nullptr) {
            qu.push(n->right);
            levels.push(level+1);
        }

        qu.pop();
        n = qu.front(); 

        levelBefore = level;
        levels.pop();
        level = levels.front();
    }
    std:: cout << std:: endl;
}