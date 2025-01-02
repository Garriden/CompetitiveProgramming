// g++ testingArrays.cpp ResizableVector.cpp -o hola  

#include "ResizableVector.hpp"

void testVector() {
    ResizableVector v;

    v.add(1);
    v.add(1);

    v.print();

    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);
    v.add(1);

    v.print();
}

int main() {
    testVector();

    return 0;
}