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
    int val = head->val;

    if(head != nullptr) {
        Node<T>* n = head;
        head = head->next;
        delete n;
    }

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
    std::cout << "::push()" << std::endl;

    if(_vectorStacks.empty()) {
        Stack<T> sta;
        _vectorStacks.push_back(sta);
    }

    Node<T>* n = new Node<T>(val);

    if(_vectorStacks[_currentStack].head == nullptr) {
        std::cout << "  s()" << std::endl;
        _vectorStacks[_currentStack].head = n;
    } else {
        std::cout << "  ds()" << std::endl;
        _vectorStacks[_currentStack].push(val);
        n->next = _vectorStacks[_currentStack].head; 
        _vectorStacks[_currentStack].head = n;
    }

    ++_currentLayer;

    if(_currentLayer == _thresh) {
        std::cout << " update stack" << std::endl;
        Stack<T> st;
        std::cout << "a" << std::endl;
        _vectorStacks.push_back(st);
        Stack<T> st2;
        std::cout << "a2" << std::endl;
        _vectorStacks.push_back(st2);
        std::cout << "b" << std::endl;
        ++_currentStack;
        _currentLayer = 0;
    }
 
}

template<typename T>
void SetOfStackS<T>::pop()
{
    //Node<T> *topNode = _vectorStacks[_currentStack];
//
    //if(topNode != nullptr) {
    //    _vectorStacks[_currentStack] = topNode->next;
    //    delete topNode;
    //}
//
    //--_currentLayer;
//
    //// See if need to remove stack.
    //topNode = _vectorStacks[_currentStack];
//
    //if(topNode == nullptr) {
    //    _vectorStacks.pop_back();
    //    --_currentStack;
    //    _currentLayer = _thresh;
    //}
}

template<typename T>
T SetOfStackS<T>::top()
{
    std::cout << "::top()" << std::endl;

    if(_vectorStacks.empty()) {
        throw std::runtime_error("Cannot get top of an empty stack");
    }

    Stack<T>& currentStack = _vectorStacks[_currentStack];

    //std::cout << currentStack.top() << std::endl;

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