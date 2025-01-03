#ifndef RESIZABLEVECTORSTRING_CPP
#define RESIZABLEVECTORSTRING_CPP

#include "ResizableVectorString.hpp"
#include <iostream>

ResizableVectorString::ResizableVectorString() : _internalVector(1),
                                                 _actualCount{0}
{
}

ResizableVectorString::ResizableVectorString(int size) : _internalVector(size),
                                                         _actualCount{0}
{
}

ResizableVectorString::~ResizableVectorString()
{
}

void ResizableVectorString::add(std::string s)
{
    int internalVectorSize = _internalVector.size();
    int stringSize = s.size();

    std::vector<std::string> v(internalVectorSize+stringSize);

    for(int ii = 0; ii < internalVectorSize; ++ii) {
        v[ii] = _internalVector[ii];
    }

    for(int ii = 0; ii < stringSize; ++ii) {
        v[internalVectorSize + ii] = s[ii];
    }

    _internalVector = v;
}

void ResizableVectorString::print()
{
    for(int ii = 0; ii < _internalVector.size(); ++ii) {
        std::cout << _internalVector[ii];
    }
    std::cout << std::endl;
}

#endif