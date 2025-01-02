#ifndef RESIZABLEVECTOR_CPP
#define RESIZABLEVECTOR_CPP

#include "ResizableVector.hpp"
#include <iostream>

ResizableVector::ResizableVector() : _internalVector(1),
                                     _actualCount{0}
{
}

ResizableVector::ResizableVector(int size) : _internalVector(size),
                                             _actualCount{0}
{
    
}

ResizableVector::~ResizableVector()
{
}

void ResizableVector::add(int x)
{
    _internalVector[_actualCount++] = x;

    if(_actualCount >= _internalVector.size()) {
        int size = _internalVector.size();
        std::vector<int> v(size*2);
        std::cout << "increase vector, new size" << ": " << size*2 << std::endl;

        // Copy internalVector into new vector.
        for(int ii = 0; ii < _internalVector.size(); ++ii) {
            v[ii] = _internalVector[ii];
        }

        _internalVector = v;
    }

}

void ResizableVector::print()
{
    for(int ii = 0; ii < _internalVector.size(); ++ii) {
        std::cout << _internalVector[ii] << ", ";
    }
    std::cout << std::endl;
}

#endif