#ifndef RESIZABLEVECTORSTRING_HPP
#define RESIZABLEVECTORSTRING_HPP

#include <vector>
#include <string>

class ResizableVectorString
{
private:
    std::vector<std::string> _internalVector;
    int _actualCount;
public:
    ResizableVectorString();
    ResizableVectorString(int size);
    ~ResizableVectorString();

    // Time O(1).
    void add(std::string s);

    void print();
};

#endif