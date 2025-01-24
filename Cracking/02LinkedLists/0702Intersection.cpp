#include <iostream>
#include <math.h>
#include <map>
#include <unordered_set>
#include "LinkedList.hpp"

// g++ .\0702Intersection.cpp LinkedList.cpp -o hola

/*
  - Brute force:
    Time complexity: O(n^2)

  - Use a map. key = Node, value = freq.
    - Iterate s1, build map.
    - Iterate s2, check map.
    Time complexity: O(n)

  - Two Pointers
    - Run each list, get the lenghts and tails.
    - On the longer list, start on his length - smaller list lenght.
    - Iterate and compare.
    Time complexity: O(n)
    Space complexity: O(1)
*/

Node* IntersectTwoPointers(Node* &n1, Node* &n2)
{
    // Run each list, get the lenghts and tails.
    Node *n1Tail = n1;
    Node *n2Tail = n2;
    int n1length = 0;
    int n2length = 0;

    while(n1Tail != nullptr) {
        n1Tail = n1Tail->next;
        ++n1length;
    }

    while(n2Tail != nullptr) {
        n2Tail = n2Tail->next;
        ++n2length;
    }

    // On the longer list, start on his length - smaller list lenght.
    int size = n2length - n1length;
    n1Tail = n1;
    n2Tail = n2;
    for(int ii = 0; ii < size; ++ii) {
        n2Tail = n2Tail->next;
    }

    if(n1length > n2length) {
        size = n1length - n2length;
        for(int ii = 0; ii < size; ++ii) {
            n1Tail = n1Tail->next;
        }
        n2Tail = n2;
    }

    // Iterate and compare.
    while(n1Tail != nullptr) {
        if(n1Tail == n2Tail) {
            return n1Tail;
        }
        n2Tail = n2Tail->next;
        n1Tail = n1Tail->next;
    }

    return nullptr;
}

Node* IntersectDS(Node* &n1, Node* &n2)
{
    std::unordered_set<Node*> s;

    // Iterate list and build map.
    while(n1 != nullptr) {
        s.insert(n1);
        n1 = n1->next;
    }

    // Iterate list while comparing to map.
    while(n2 != nullptr) {
        if(s.count(n2) > 0) {
            return n2;
        }
        n2 = n2->next;
    }

    return nullptr;
}

int main()
{
    Node* n = new Node(24, nullptr);
    LinkedList::Insert(n, 10);
    LinkedList::Insert(n, 11);
    LinkedList::Insert(n, 4);
    LinkedList::Insert(n, 12);
    LinkedList::Insert(n, 13);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 1);
    LinkedList::Insert(n, 0);
    LinkedList::Insert(n, 5);
    LinkedList::PrintList(n);

    Node* n2 = new Node(24, nullptr);
    LinkedList::Insert(n2, 10);
    n2->next->next = n->next->next->next;
    LinkedList::PrintList(n2);

    std::cout << IntersectTwoPointers(n, n2)->data << std::endl;

    return 0;
}