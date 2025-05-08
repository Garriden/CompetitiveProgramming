#include <iostream>
#include <cstdint>
#include <math.h>
#include <string.h>

// g++ .\0305FlipBitToWin.cpp -o hola

// Two Pointers.

int main()
{
    int max = 0;
    int lastOnes = 0;
    int count = 0;
    std::string s = "11011101111";

    for(int ii = 0; ii < s.size(); ++ii) {
        if(s[ii] == '1') {
            ++count;
        } else {
            if(lastOnes + count + 1 > max) {
                max = lastOnes + count + 1;
            }
            lastOnes = count;
            count = 0;
        }
    }

    if(lastOnes + count + 1 > max) {
        max = lastOnes + count + 1;
    }

    std::cout << max << std::endl;

    return 0;
}