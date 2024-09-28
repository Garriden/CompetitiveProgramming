// Input:  N = 10000000000, M = 10011, i = 2, j = 6
// Output: N = 10001001100

#include <cstdint>
#include <iostream>
#include <bitset>

int32_t insertion(int32_t N, int32_t M, int i, int j)
{
    int32_t Msize = j - i + 1;
    int32_t mask = ~ (1 << Msize) << i;
    N = N & mask;
    int32_t insert = M << i;

    return N | insert;
}

int main()
{
    auto result = insertion(0b10000000000, 0b10011, 2, 6);
    std::cout << std::bitset<16>(result);
}
