// g++ testingArrays.cpp ResizableVectorString.cpp ResizableVector.cpp -o hola  

#include "ResizableVector.hpp"
#include "ResizableVectorString.hpp"

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

void testVectorString() {
    ResizableVectorString stringBuilder;

    stringBuilder.add("hola");
    stringBuilder.add("adeu");
    stringBuilder.add("pasiube");

    stringBuilder.print();
}

int main() {
    testVectorString();

    return 0;
}