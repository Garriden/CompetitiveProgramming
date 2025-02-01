#ifndef MY_STACK_H
#define MY_STACK_H

#include <iostream>

template<typename U> class Node {
public:
    Node(U v);
    void setNext(Node<U>* n);
private:
    Node<U>* next;
    U val;
    template<typename T> friend class Stack;
};

template<typename U> 
Node<U>::Node(U v) : 
    val{v}, 
    next{nullptr} 
{}

template<typename U> 
void Node<U>::setNext(Node<U>* n)
{ 
    next = n;
}

template<typename T> 
class Stack {
public:
    Stack();
    ~Stack();
    void push(T val);
    void pop();
    T top();
    bool isEmpty();
    int min();

private:
    Node<T> *head;
    int minim;
};

template<typename T>
Stack<T>::Stack() : 
   head{nullptr},
   minim{INT_MAX}
{}

template<typename T>
void Stack<T>::push(T val)
{
    Node<T>* n = new Node<T>(val);
    if(head == nullptr) {
      head = n;
    } else {
      n->next = head; 
      head = n;
    }

    if(val < minim) {
        minim = val;
    }
}

template<typename T>
void Stack<T>::pop()
{
    if(head != nullptr) {
        Node<T>* n = head;
        head = head->next;
        delete n;
    }
}

template<typename T>
T Stack<T>::top()
{
    if(head != nullptr) {
        return head->val;
    }
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return (head == nullptr);
}

template<typename T>
int Stack<T>::min()
{
    return (minim);
}

template<typename T>
Stack<T>::~Stack(){
    while(head != nullptr) {
        Node<T>* n = head; 
        pop();
    }
}

#endif