#include "LinkedList.hpp"
#include <iostream>

namespace LinkedList {
    void Insert(Node* &head, int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void InsertTail(Node* &head, int data)
    {
        Node* runner = head;
        while(runner->next != nullptr) {
            runner = runner->next;
        }

        Node* newNode = new Node;
        newNode->data = data;
        runner->next = newNode;
    }

    void RemoveHead(Node* &head)
    {
        if(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void RemoveNode(Node* &previous, Node* &node)
    {
        if (node != nullptr) {
            Node* tmp = node;
            node = node->next;
            previous->next = node;
            delete tmp;
        }
    }

    Node* ReverseList(Node* &n)
    {
        Node* nImpostor = n;
        Node* retHead = new Node(n->data);

        nImpostor = nImpostor->next;
        while(nImpostor != nullptr) {
            Node *aux = new Node(nImpostor->data);
            aux->next = retHead;
            retHead = aux;
            nImpostor = nImpostor->next;
        }

        //while(retHead != nullptr) {
        //    std:: cout << retHead->data << " ";
        //    retHead = retHead->next;
        //}

        return retHead;
    }

    void PrintList(Node* head) 
    {
        while(head != nullptr) {
            std::cout << head->data << "-->";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};