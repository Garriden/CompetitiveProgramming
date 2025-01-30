#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>

template<typename U> class Node {
public:
    Node(U v);
    void setNext(Node<U>* n);
private:
    Node<U>* next;
    U val;
    template<typename T> friend class Queue;
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
class Queue {
public:
    Queue();
    ~Queue();
    void push(T val);
    void pop();
    T front();
    T back();
    bool isEmpty();

private:
    Node<T> *first;
    Node<T> *last;
};

template<typename T>
Queue<T>::Queue() : 
   first{nullptr}
{}

template<typename T>
void Queue<T>::push(T val)
{
    Node<T>* n = new Node<T>(val);
    if(first == nullptr) {
        first = n;
        last = n;
    } else {
        last->next = n; 
        last = n;
    }
}

template<typename T>
void Queue<T>::pop()
{
    if(first != nullptr) {
        Node<T>* n = first;
        first = first->next;
        delete n;
    }
}

template<typename T>
T Queue<T>::front()
{
    if(first != nullptr) {
        return first->val;
    }
}

template<typename T>
T Queue<T>::back()
{
    if(first != nullptr) {
        return last->val;
    }
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return (first == nullptr);
}

template<typename T>
Queue<T>::~Queue(){
    while(first != nullptr) {
        Node<T>* n = first; 
        pop();
    }
}

#endif