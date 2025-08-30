#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <numeric> // Required for std::accumulate
#include <chrono>
#include <random>

// g++ -std=c++17 2316Rand7FromRand5.cpp -o hola

// Rejection sampling method.
//  Generate larger range: Rand5() * 5 + Rand5() => [0, 24]
//  If the number falls outside the desired subset, you simply discard it and try again.

// Trust the Theory, Not the Buggy Output.
//  Rand5 function is NOT fully random and independent between calls.

static auto now = std::chrono::system_clock::now();
static auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
static std::mt19937 generator(milliseconds);
static std::uniform_int_distribution<int> distribution(0, 4);

int Rand5() {
    return distribution(generator);
}

int Rand7() {
    int ret = Rand5() * 5 + Rand5(); // Range: [0, 24]

    while(ret > 21) { // Range needed: [0, 20]
        ret = Rand5() * 5 + Rand5(); // Generate it again.
    }

    return ret % 7;
} // 18208 13624 13570 13696 13526 13771 13605 

// Non-Uniform Distribution. Tends towards a bell curve.
int Rand7Bad() {
    return (Rand5()+Rand5()+Rand5()+Rand5()+Rand5()+Rand5()+Rand5()) % 7;
} // 14171 14447 14327 14371 14381 14244 14059 

int main()
{
    //std::cout << Rand7() << std::endl;

    std::vector<int> v(7, 0);
    for(int ii = 0; ii < 100000; ++ii) {
        v[Rand7()]++;
    }

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    } std::cout << std::endl;

    return 0;
}