#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ -std=c++20 1108Coins.cpp -o hola

// Find the number of ways ... 

int Coins(int n, std::vector<int> denoms, int index, std::vector<std::vector<int> > memo)
{
    if(memo[n][index] > 0) {
        return memo[n][index];
    }

    int coin = denoms[index];

    if(index == denoms.size() - 1) {
        int remaining = n % coin;
        return (remaining == 0) ? 1 : 0;
    }

    int ways = 0;
    for(int amount = 0; amount <= n; amount += coin) {
        ways += Coins(n - amount, denoms, index + 1, memo);
    }

    memo[n][index] = ways;
    return ways;
}

int main()
{
    int n = 24;
    std::vector<int> v = {25, 10, 5, 1};
    std::vector<std::vector<int> > memo(n + 1, std::vector<int>(v.size()) );
    std::cout << Coins(n, v, 0, memo) << std::endl;
    return 0;
}