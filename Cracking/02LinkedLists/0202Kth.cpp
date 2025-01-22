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
            LinkedList::InsertTail(ret, head->data);
        }
        ++ii;
        head = head->next;
    }

    return ret;
}

int main()
{
    Node* n = new Node(24, nullptr);

    LinkedList::Insert(n, 10);
    LinkedList::Insert(n, 11);
    LinkedList::Insert(n, 12);
    LinkedList::Insert(n, 13);
    LinkedList::Insert(n, 2);
    LinkedList::Insert(n, 1);
    LinkedList::Insert(n, 0);
    LinkedList::Insert(n, 4);
    LinkedList::Insert(n, 5);
    LinkedList::PrintList(n);

    int i = 1;
    LinkedList::PrintList(KthRecursive(n, 6, i));
    //LinkedList::PrintList(KthIterate(n, 6));
    //LinkedList::PrintList(Kth(n, 6));

    return 0;
}