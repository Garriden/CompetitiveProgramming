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
#include <queue>

// g++ -std=c++17 2616Calculator.cpp -o hola

//

enum operations {
    ADD,
    REST,
    MULT,
    DIV
};

int main()
{
    // 2 * 3 + 5 / 6 * 3 + 15
    std::vector<double> v;
    int it = -1;

    // First, operate over mults and divs.
    v.push_back(2.0);
    ++it;
    // mult.
    v[it] *= 3.0;
    // sum. if rest, add negative number.
    v.push_back(5.0); // sum is NOT prioritary.
    ++it;
    // div.
    v[it] /= 6.0;
    // mult.
    v[it] *= 3.0;
    // sum.
    v.push_back(15.0); // sum is NOT prioritary.
    ++it;

    // Second, operate over sums and rests.
    double result = std::accumulate(v.begin(), v.end(), 0.0); // Oju, 0.0 for a double result.

    std::cout << result << std::endl;
    //std::cout << 2 * 3 + double(5) / double(6) * 3 + 15 << std::endl;

    return 0;
}