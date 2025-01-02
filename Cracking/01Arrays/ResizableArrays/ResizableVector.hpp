#ifndef RESIZABLEVECTOR_HPP
#define RESIZABLEVECTOR_HPP

#include <vector>

class ResizableVector
{
private:
    std::vector<int> _internalVector;
    int _actualCount;
public:
    ResizableVector();
    ResizableVector(int size);
    ~ResizableVector();

    // Time O(1).
    void add(int x);

    void print();
};

#endif