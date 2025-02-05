#ifndef MY_STACK_H
#define MY_STACK_H

#include <iostream>
#include <vector>

template<typename U> class Node {
public:
    Node(U v);
    void setNext(Node<U>* n);
private:
    Node<U>* next; // Upointer
    U val;
    template<typename T> friend class Stack;
    template<typename T> friend class SetOfStackS;
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
    Node<T> *head;

    // Copy Constructor (Deep Copy)
    Stack(const Stack& other) : head(nullptr), minim(INT_MAX) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push(current->val);
            current = current->next;
        }
        minim = other.minim;
    }

private:
    int findNewMin();
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
    if (head == nullptr) {
        throw std::runtime_error("Cannot pop from an empty stack");
    }

    Node<T>* n = head;
    T val = head->val;
    head = head->next;
    delete n;

    if(val == minim) {
        minim = findNewMin();
    }
}

template<typename T>
T Stack<T>::top()
{
    if(head == nullptr) {
        throw std::runtime_error("Cannot get top of an empty stack");
    }
    return head->val;
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
int Stack<T>::findNewMin()
{
    int minRet = INT_MAX;

    Node<T>* n = head;
    while(n != nullptr) {
        if(n->val < minRet) {
            minRet = n->val;
        }
        n = n->next;
    }
    delete n;

    return minRet;
}

template<typename T>
Stack<T>::~Stack(){
    while(head != nullptr) {
        Node<T>* n = head; 
        pop();
    }
}


template<typename T> 
class SetOfStackS {
public:
    SetOfStackS();
    SetOfStackS(int x);
    ~SetOfStackS();
    void push(T val);
    void pop();
    T top();
    bool isEmpty();

private:
    std::vector<Stack<T> > _vectorStacks; //upointer
    int _thresh;
    int _currentStack;
    int _currentLayer;
};


template<typename T>
SetOfStackS<T>::SetOfStackS() : 
   _vectorStacks(),
   _thresh{},
   _currentStack{0},
   _currentLayer{0}
{}

template<typename T>
SetOfStackS<T>::SetOfStackS(int x) : 
   _vectorStacks(),
   _thresh{x},
   _currentStack{0},
   _currentLayer{0}
{}

template<typename T>
void SetOfStackS<T>::push(T val)
{
    if(_vectorStacks.empty()) {
        Stack<T> sta;
        _vectorStacks.push_back(sta);
    }

    Node<T>* n = new Node<T>(val);
    _vectorStacks[_currentStack].push(val);

    ++_currentLayer;

    if(_currentLayer == _thresh) {
        std::cout << " update stack" << std::endl;
        Stack<T> st;
        _vectorStacks.push_back(st);
        ++_currentStack;
        _currentLayer = 0;
    }
 
}

template<typename T>
void SetOfStackS<T>::pop()
{
    if (_vectorStacks.empty()) {
        throw std::runtime_error("SetOfStacks is empty");
    }

    if (_vectorStacks[_currentStack].isEmpty()) {
        throw std::runtime_error("Current stack is unexpectedly empty before pop");
    }

    _vectorStacks[_currentStack].pop();

    if(_vectorStacks[_currentStack].isEmpty()) {
        _vectorStacks.pop_back();
        --_currentStack;
        _currentLayer = _thresh;
    }

}

template<typename T>
T SetOfStackS<T>::top()
{
    if(_vectorStacks.empty()) {
        throw std::runtime_error("Cannot get top of an empty stack");
    }

    Stack<T>& currentStack = _vectorStacks[_currentStack];

    return currentStack.top();
}

template<typename T>
bool SetOfStackS<T>::isEmpty()
{
    return _vectorStacks.empty();
}

template<typename T>
SetOfStackS<T>::~SetOfStackS(){
    while(!_vectorStacks.empty()) {
        _vectorStacks.pop_back();
    }
}


#endif