#include <iostream>

/*
  Just iterate. Auxiliar structure. unordered_set?
    Time complexity: O(n)

    Without auxiliar buffer/data structure:
      - Sort list.
      - Two pointers
      Time complexity: O(n)
*/

#include <iostream>
#include <unordered_set>

struct Node {
    int data = 0;
    Node* next = nullptr;
};


void insert(Node* &head, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void removeHead(Node* &head)
{
    if(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//void remove(Node* &previous, Node* &node)
//{
//    if(node != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//}

void printList(Node* head) 
{
    while(head != nullptr) {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

void removeDups(Node* head)
{
    Node* previous = nullptr;
    std::unordered_set<int> set;

    while(head != nullptr) {
        //std::cout << head->data << " count: " << set.count(head->data) << std::endl;
        if(set.count(head->data) > 0) {
            Node* tmp = head;
            head = head->next;
            previous->next = head;
            delete tmp;
        } else {
            set.insert(head->data);
            previous = head;
            head = head->next;
        }
    }

}

int main()
{
    Node* n = new Node;
    insert(n, 0);
    insert(n, 1);
    insert(n, 2);
    insert(n, 3);
    insert(n, 2);
    insert(n, 2);
    insert(n, 3);
    insert(n, 2);
    insert(n, 2);
    printList(n);

    removeDups(n);
    printList(n);

    return 0;
}