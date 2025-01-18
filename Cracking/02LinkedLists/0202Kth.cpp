#include <iostream>
#include "LinkedList.hpp"

// g++ .\0202Kth.cpp LinkedList.cpp -o hola

/*
  Just iterate. (If recursive space is O(n) too)
    Time complexity: O(n)
*/

Node* Kth(Node* &head, int k)
{
    Node* ret = new Node;
    int ii = 1;

    while(head != nullptr) {
        if(ii == k) {
            return head;
        }
        ++ii;
        head = head->next;
    }

    return ret;
}

Node* KthRecursive(Node* &head, int k, int &i) 
{
    if(head == nullptr) {
        return nullptr;
    } else {
        Node* ret = KthRecursive(head->next, k, i);
        ++i;
        if(i == k) {
            return head;
        }
        return ret;
    }
}

Node* KthIterate(Node* &head, int k)
{
    Node* ret = nullptr;
    int ii = 1;
    bool found = false;

    while(head != nullptr) {
        if(!found && ii == k) {
            found = true;
            ret = new Node(head->data);
        } else if(found) {
            LinkedList::insertTail(ret, head->data);
        }
        ++ii;
        head = head->next;
    }

    return ret;
}

int main()
{
    Node* n = new Node(24, nullptr);

    LinkedList::insert(n, 10);
    LinkedList::insert(n, 11);
    LinkedList::insert(n, 12);
    LinkedList::insert(n, 13);
    LinkedList::insert(n, 2);
    LinkedList::insert(n, 1);
    LinkedList::insert(n, 0);
    LinkedList::insert(n, 4);
    LinkedList::insert(n, 5);
    LinkedList::printList(n);

    int i = 1;
    LinkedList::printList(KthRecursive(n, 6, i));
    //LinkedList::printList(KthIterate(n, 6));
    //LinkedList::printList(Kth(n, 6));

    return 0;
}