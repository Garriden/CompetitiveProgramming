#include <iostream>
#include "LinkedList.hpp"
#include <unordered_set>

// g++ .\0102RemoveDuplicates.cpp LinkedList.cpp -o hola

/*
  Just iterate. Auxiliar structure. unordered_set?
    Time complexity: O(n)

    Without auxiliar buffer/data structure:
      - Two pointers. the runner pointer removes all the elements equal to the current pointer.
      Time complexity: O(n^2)
*/

void removeDups(Node* head)
{
    Node* previous = nullptr;
    std::unordered_set<int> set;

    while(head != nullptr) {
        //std::cout << head->data << " count: " << set.count(head->data) << std::endl;
        if(set.count(head->data) > 0) {
            LinkedList::RemoveNode(previous, head);
        } else {
            set.insert(head->data);
            previous = head;
            head = head->next;
        }
    }
}

int main()
{
    Node* n = new Node{0, nullptr};

    LinkedList::Insert(n, 0);
    LinkedList::Insert(n, 1);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 3);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 3);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 2);
    LinkedList::PrintList(n);

    removeDups(n);
    LinkedList::PrintList(n);

    return 0;
}