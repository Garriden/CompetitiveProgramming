#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(int val);

    int value;
    Node* left;
    Node* right;
};

#endif