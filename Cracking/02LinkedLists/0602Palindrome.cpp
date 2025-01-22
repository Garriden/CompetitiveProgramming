#include <iostream>
#include <math.h>
#include <vector>
#include "LinkedList.hpp"

// g++ .\0602Palindrome.cpp LinkedList.cpp -o hola

/*
  · Just iterate (vector).
    - Iterate list and build vector.
    - Iterate list while comparing to vector.
    Time complexity: O(n)

  · Reverse list and compare.
  · Stack(half of the list).
*/

bool isPalindrome(Node* &n)
{
    std::vector<int> v;
    Node* aux = n;

    // Iterate list and build vector.
    while(aux != nullptr) {
        v.push_back(aux->data);
        aux = aux->next;
    }

    int it = v.size()-1;
    // Iterate list while comparing to vector.
    while(n != nullptr) {
        if(v[it--] != n->data) {
            return false;
        }
        n = n->next;
    }

    return true;
}

bool isPalindromeList(Node* &n)
{
    Node* reversed = LinkedList::ReverseList(n);

    while(n != nullptr) {
        if(reversed->data != n->data) {
            return false;
        }
        n = n->next;
        reversed = reversed->next;
    }

    return true;
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
    std::cout << isPalindrome(n) << std::endl;

    Node* n2 = new Node(24, nullptr);
    LinkedList::Insert(n2, 10);
    LinkedList::Insert(n2, 10);
    LinkedList::Insert(n2, 24);
    LinkedList::PrintList(n2);
    std::cout << isPalindrome(n2) << std::endl;

    Node* n22 = new Node(24, nullptr);
    LinkedList::Insert(n22, 10);
    LinkedList::Insert(n22, 10);
    LinkedList::Insert(n22, 24);
    LinkedList::PrintList(n22);
    std::cout << isPalindromeList(n22) << std::endl;

    Node* n42 = new Node(24, nullptr);
    LinkedList::Insert(n42, 86);
    LinkedList::Insert(n42, 15);
    LinkedList::Insert(n42, 24);

    LinkedList::PrintList(n42);
    std::cout << isPalindromeList(n42) << std::endl;

    return 0;
}