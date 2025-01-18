#include "LinkedList.hpp"
#include <iostream>

namespace LinkedList {
    void insert(Node* &head, int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertTail(Node* &head, int data)
    {
        Node* runner = head;
        while(runner->next != nullptr) {
            runner = runner->next;
        }

        Node* newNode = new Node;
        newNode->data = data;
        runner->next = newNode;
    }

    void removeHead(Node* &head)
    {
        if(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeNode(Node* &previous, Node* &node)
    {
        if (node != nullptr) {
            Node* tmp = node;
            node = node->next;
            previous->next = node;
            delete tmp;
        }
    }

    void printList(Node* head) 
    {
        while(head != nullptr) {
            std::cout << head->data << "-->";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};