#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "Node.hpp"
#include <iostream>
#include <queue>

// g++ BinaryHeap.cpp Node.cpp UtilsNode.cpp -o hola

/*
        4
     /     \
   50        7
  /   \     /
55    99  87
*/

void BubbleSortDownMaximum(Node* n)
{
    int max = n->value;
    int leftValue, rightValue;

    while(n->left != nullptr && n->right != nullptr) {
        leftValue = n->left->value;
        rightValue = n->right->value;

        if(leftValue < rightValue) {
            n->value = leftValue;
            n = n->left;
            n->value = max;
        } else {
            n->value = rightValue;
            n = n->right;
            n->value = max;
        }
    }

} 

void BubbleSortUpMinimum(Node* newLeaf) 
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

/*
 - Find leafs (BFS).
 - Compare leaf with leaf before. Return position.
 - If all leafs have the same level, insert into innermost left.
 - Just insert Node into there.
 - Bubble minimum element inserted up.
 */
void Insert(Node* n, int value)
{
    int maxLevel = Node::GetMaxLevelBFS(n);
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
            BubbleSortUpMinimum(newLeaf);
            return;
        } else if(n->right == nullptr) {
            Node* newLeaf = new Node(value);
            n->right = newLeaf;
            newLeaf->parent = n;
            BubbleSortUpMinimum(newLeaf);
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
    BubbleSortUpMinimum(newLeaf);
}

/*
 - Get first node value.
 - Find Bottommost rightmost one, erase it and put its value to the root.
 - Bubble down this maximum value (now in root).
 */
int ExtractMin(Node* n)
{
    int returnValue = n->value;
    
    int maxLevel = Node::GetMaxLevelBFS(n);
    int level = 1;

    std::queue<Node *> qu;
    std::queue<int> levels;
    Node* root = n;
    qu.push(n);
    levels.push(1);

    while(!qu.empty()) {
        //std::cout << "Node: " << n->value << "  / level: " << level << std::endl;

        // Check if that node is the bottommost, rightmost one.
        if(level == maxLevel) {
            //std::cout << "Node: " << n->value << "  / parent: " << n->parent->value <<  "  / level: " << level << std::endl;
            int maximumValue = n->value;

            if(n->parent->right != nullptr && n->parent->right->value == maximumValue) {
                n->parent->right = nullptr;
            } else if(n->parent->left->value == maximumValue) {
                n->parent->left = nullptr;
            }

            root->value = maximumValue;
            BubbleSortDownMaximum(root);
            return returnValue;
        }

        // BFS - Iterate from right to left.
        if(n->right != nullptr) {
            qu.push(n->right);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->right->value << "  / level: " << level+1 << std::endl;
        }

        if(n->left != nullptr) {
            qu.push(n->left);
            levels.push(level+1);
            //std::cout << "PUSH Node: " << n->left->value << "  / level: " << level+1 << std::endl;
        }

        qu.pop();
        n = qu.front(); 

        levels.pop();
        level = levels.front();
    }

    return returnValue;
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

    Node::PrintBinaryTree(n);

    Insert(n, 2);

    Node::PrintBinaryTree(n);

    std::cout << "Min value: " << ExtractMin(n) << std::endl;

    Node::PrintBinaryTree(n);


    return 0;
}

#endif