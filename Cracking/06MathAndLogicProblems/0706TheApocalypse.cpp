#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>
#include <random>
#include <limits> // Required for numeric_limits

// g++ -std=c++20 0706TheApocalypse.cpp -o hola

double generateRandomReal(double minVal, double maxVal) {
    // Create a uniform real distribution object that produces values
    // in the inclusive range [minVal, maxVal].
    std::uniform_real_distribution<double> distribution(minVal, maxVal);

    // Create a Mersenne Twister pseudo-random number generator.
    // You can seed it with a specific value for reproducibility if needed.
    std::mt19937 generator;
    generator.seed(std::random_device{}()); // Seed with a non-deterministic random value

    // Generate and return a random real number within the specified range.
    return distribution(generator);
}




int main()
{
    int n = 10000;
    int girls = 0;
    int boys = 0;
    int totalGirls = 0;
    int totalBoys = 0;
    bool hasGirl = false;

    double minValue = 0.0;
    double maxValue = 1.0;

    for(int ii = 0; ii < n; ++ii) {
        hasGirl = false;
        while(!hasGirl) {
            if(generateRandomReal(minValue, maxValue) < 0.5) {
                ++girls;
                hasGirl = true;
            } else {
                ++boys;
            }
        }
        //std::cout << "This family has " << girls << " girl and " << boys << " boys" << std::endl;
        totalBoys += boys;
        totalGirls += girls;
        girls = 0;
        boys = 0;
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "girls: " << totalGirls << std::endl;
    std::cout << "boys:  " << totalBoys << std::endl;
    std::cout << "boys total population: " << (double(totalBoys) / double(totalGirls+totalBoys)) * 100 <<  "%" << std::endl;

    return 0;
}