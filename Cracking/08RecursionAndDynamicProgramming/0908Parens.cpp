#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>

// g++ -std=c++20 0908Parens.cpp -o hola

// Memorization? Very slow

void AddParens(int left, int right, std::string s1, int index)
{
    if(left < 0 || right < left) {
        return;
    }

    if(left == 0 && right == 0) {
        std::cout << s1 << std::endl;
    } else {
        s1[index] = '(';
        AddParens(left - 1, right, s1, index + 1);

        s1[index] = ')';
        AddParens(left, right - 1, s1, index + 1);
    }

}

int main()
{
    int cont = 3;
    std::string s = "                  ";
    AddParens(cont, cont, s, 0);

    return 0;
}