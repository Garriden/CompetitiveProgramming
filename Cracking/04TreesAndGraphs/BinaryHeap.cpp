#include "Node.hpp"
#include <iostream>
#include <queue>
#include <bitset>

// g++ BinaryHeap.cpp Node.cpp -o hola

/*
        4
     /     \
   50        7
  /   \     /
55    99  87

 - Find leafs (BFS).
 - Compare leaf with leaf before. Return position.
 - If all leafs have the same level, insert into innermost left.
 - How to store path? Another queue? Bitset? No need, just insert Node into there.

*/

int GetMaxLevelBFS(Node* n) {
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
void PrintBinaryTree(Node* n)
{
    int maxLevel = GetMaxLevelBFS(n);
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

void BubbleSortMinimum(Node* newLeaf) 
{
    int aux;

    while(newLeaf->parent != nullptr && newLeaf->value < newLeaf->parent->value) {
        //std::cout << "newLeaf: " << aaa->value << "  / newLeaf->parent: " << aaa->parent->value << std::endl;

        aux = newLeaf->parent->value;
        newLeaf->parent->value = newLeaf->value;
        newLeaf->value = aux;
        newLeaf = newLeaf->parent;
    }
}

void InsertIntoComplentePosition(Node* n, const int &value) 
{
    int maxLevel = GetMaxLevelBFS(n);
    int level = 1;

    std::queue<Node *> qu;
    std::queue<int> levels;
    Node* root = n;
    qu.push(n);
    levels.push(1);

    while(!qu.empty()) {
        //std::cout << "Node: " << n->value << "  / level: " << level << std::endl;

        // Check if that node is the good one to make the tree complete after an insert.
        if((n->left == nullptr && n->right == nullptr) && (level != maxLevel)) {
            Node* newLeaf = new Node(value);
            n->left = newLeaf;
            newLeaf->parent = n;
            BubbleSortMinimum(newLeaf);
            return;
        } else if(n->right == nullptr) {
            Node* newLeaf = new Node(value);
            n->right = newLeaf;
            newLeaf->parent = n;
            BubbleSortMinimum(newLeaf);
            return;
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

    // Perfect Binary Tree, insert element innermost left.
    while(root->left != nullptr) {
        root = root->left;
    }
    Node* newLeaf = new Node(value);
    root->left = newLeaf;
    newLeaf->parent = root;
    BubbleSortMinimum(newLeaf);
}

void Insert(Node* n, int value)
{
    InsertIntoComplentePosition(n, value);

    PrintBinaryTree(n);
}

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

    PrintBinaryTree(n);

    Insert(n, 2);

    return 0;
}