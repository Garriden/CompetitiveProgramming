#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>

// g++ -std=c++20 0508RecursiveMultiply.cpp -o hola

// Memorization.

int Product(int smaller, int bigger, std::vector<int> memo)
{
    //std::cout << "smaller: " << smaller << std::endl;
    // if smaller 0 ?
    if(smaller == 1) { // Base case.
        return bigger; // the multiplication!
    } else if(memo[smaller] > 0) { // Memorization case.
        return memo[smaller];
    }

    // Compute half. If odd, compute other half. If even, double it.
    int s = smaller >> 1; // Divide by 2.
    int side1 = Product(s, bigger, memo); // Compute half.
    int side2 = 0;
    if(smaller % 2 == 1) { // odd
        side2 = Product(smaller - s, bigger, memo);
    } else {
        side2 = side1; // If two halves equal. Already processed in last line.
    }

    // Memorization chache.
    if(memo[smaller] == 0) {
        memo[smaller] = side1 + side2;
        std::cout << "smaller: " << smaller << "  / memo[smaller]: " << memo[smaller] << std::endl;
    }
    return memo[smaller];
}


int main()
{
    std::vector<int> memo(23 + 1, 0);

    std::cout << Product(17, 23, memo) << std::endl;


    return 0;
}