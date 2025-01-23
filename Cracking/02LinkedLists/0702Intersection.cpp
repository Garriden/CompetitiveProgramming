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

  - Two Pointers?
    Time complexity: O(n)
    Space complexity: O(1)
*/

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

    std::cout << IntersectDS(n, n2)->data << std::endl;

    return 0;
}