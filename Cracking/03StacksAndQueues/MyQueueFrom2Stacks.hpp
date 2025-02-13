#ifndef MY_QUEUE_STACKS_H
#define MY_QUEUE_STACKS_H

#include <stack>
#include <iostream>

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
    std::stack<T> _stack1;
    std::stack<T> _stack2;
    T _front;
    T _back;
};

template<typename T>
Queue<T>::Queue() : 
   _stack1{},
   _stack2{},
   _front{},
   _back{}
{}

template<typename T>
void Queue<T>::push(T val)
{
    if(_stack1.empty() && _stack2.empty()) {
        _front = val;
    }
    _stack1.push(val);
    _back = val;
    std::cout << "::pushed " << _stack1.top() << std::endl;
}

template<typename T>
void Queue<T>::pop()
{
    while(!_stack1.empty()) {
        _stack2.push(_stack1.top());
        _stack1.pop();
    }
    std::cout << _stack2.top() << " is ::poped." << std::endl;
    _stack2.pop();
    _front = _stack2.top();
}

template<typename T>
T Queue<T>::front()
{
    return _front;
}

template<typename T>
T Queue<T>::back()
{
    return _back;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return (_stack1.empty() && _stack2.empty());
}

template<typename T>
Queue<T>::~Queue()
{
}

#endif