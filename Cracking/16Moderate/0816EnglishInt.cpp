#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 0816EnglishInt.cpp -o hola

int countDigits(int x) {
    int cont = 0;
    int aux = x;

    while(aux > 9) {
        aux /= 10;
        ++cont;
    }

    return cont + 1;
}

std::string OneDigit(int x) {
    if(x == 0) return " zero";
    if(x == 1) return " one";
    if(x == 2) return " two";
    if(x == 3) return " three";
    if(x == 4) return " four";
    if(x == 5) return " five";
    if(x == 6) return " six";
    if(x == 7) return " seven";
    if(x == 8) return " eight";
    if(x == 9) return " nine";

    return "";
}

std::string TwoDigits(int x) {
    if(x == 10) return " ten";
    if(x == 11) return " eleven";
    if(x == 12) return " twelve";
    if(x == 13) return " thirdteen";
    if(x == 14) return " fourteen";
    if(x == 15) return " fifthteen";
    if(x == 16) return " sixteen";
    if(x == 17) return " seventeen";
    if(x == 18) return " eighteen";
    if(x == 19) return " nineteen";
    if(x == 20) return " twenty";
    if(x > 20 && x < 30) return " twenty" + OneDigit(x%10);
    if(x == 30) return " thirthy";
    if(x > 30 && x < 40) return " thirthy" + OneDigit(x%10);
    if(x == 40) return " fourthy";
    if(x > 40 && x < 50) return " fourthy" + OneDigit(x%10);
    if(x == 50) return " fifthy";
    if(x > 50 && x < 60) return " fifthy" + OneDigit(x%10);
    if(x == 60) return " sixthy";
    if(x > 60 && x < 70) return " sixthy" + OneDigit(x%10);
    if(x == 70) return " seventy";
    if(x > 70 && x < 80) return " seventy" + OneDigit(x%10);
    if(x == 80) return " eighty";
    if(x > 80 && x < 90) return " eighty" + OneDigit(x%10);
    if(x == 90) return " ninety";
    if(x > 90 && x < 100) return " ninety" + OneDigit(x%10);

    return "";
}

int main()
{
    int n1 = 1358123;
    int n = n1;
    int x, x2 = 0;
    int cont = countDigits(n1);
    std::string s = "";

    while(cont > 0) {
        x = n1 / (int)(std::pow(10, cont-1)); // check first digit.
        x2 = n1 / (int)(std::pow(10, cont-2)); // check firsts two digits.
        //std::cout << " x: " << x << "  x2: " << x2 << std::endl;
        if(cont % 3 == 1) {
            s += OneDigit(x);

            if(cont == 7) {
                s += " milion";
            } else if(cont == 4) {
                s += " thousand";
            }
        } else if(cont % 3 == 2) {
            s += TwoDigits(x2);
            --cont;

            if(cont == 8) {
                s += " milion";
            } else if(cont == 5) {
                s += " thousand";
            }
        } else if(cont % 3 == 0) {
            s += OneDigit(x) + " houndred";
        }

        n1 = n1 % (int)(std::pow(10, cont-1));
        --cont;
    }

    std::cout << n << " -> " << s << std::endl;

    return 0;
}