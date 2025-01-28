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

        Node* nAux = n;
        while(nAux != nullptr) {
            std:: cout << nAux->data << " ";
            nAux = nAux->next;
        }

        return retHead;
    }

    Node* ReverseList2(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;

        while (curr != nullptr) {
            next = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = next;
        }


        Node* nAux = prev;
        while(nAux != nullptr) {
            std:: cout << nAux->data << " ->";
            nAux = nAux->next;
        }

        return prev;
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