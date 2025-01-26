#include <iostream>
#include "LinkedList.hpp"

// g++ .\0802LoopDetection.cpp LinkedList.cpp -o hola

/*
  - Two Pointers. Runner
      Time complexity: O(n)
      Space complexity: O(1)
*/

bool LoopDetection(Node* &n1)
{
    Node *runner = n1->next;

    int it = 0;
    while(it < 100) { // Get list length?
        if(n1 == nullptr or runner == nullptr or runner->next == nullptr) {
            return false;
        } else if(n1 == runner) {
            return true;
        }

        n1 = n1->next;
        runner = runner->next->next;
        ++it;
    }

    return false;
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

    std::cout << LoopDetection(n) << std::endl;

    Node* n2 = new Node(24, nullptr);
    Node* n2Head = n2;
    LinkedList::InsertTail(n2, 10);
    LinkedList::InsertTail(n2, 11);
    LinkedList::InsertTail(n2, 4);
    LinkedList::InsertTail(n2, 12);
    LinkedList::InsertTail(n2, 13);
    LinkedList::InsertTail(n2, 2);
    LinkedList::InsertTail(n2, 1);
    LinkedList::InsertTail(n2, 0);
    LinkedList::InsertTail(n2, 5);
    n2->next = n2Head;

    std::cout << "The second list has a Loop, I won't print the list." << std::endl;
    std::cout << LoopDetection(n2) << std::endl;

    return 0;
}