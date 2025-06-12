#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <algorithm>

// g++ -std=c++20 0708PermutationsWithoutDups.cpp -o hola


void PermutationsFast(std::string s)
{
    do {
        std::cout << s << std::endl;
    } while(std::next_permutation(s.begin(), s.end()));
}
/*
std::vector<std::string> PermutationsRecursive(std::string remainder)
{
    int n = remainder.size();
    std::vector<std::string> result;

    if(n == 0) { // Base case.
        result.push_back("");
        return result;
    }

    for(int ii = 0; ii < n; ++ii) {
        std::string before = remainder.substr(0, ii);
        std::string after = remainder.substr(ii + 1, n);

        std::vector<std::string> partials = PermutationsRecursive(before + after);

        // SubPermutations.
        for(int jj = 0; jj < partials.size(); ++jj) {
            //std::cout << remainder[ii] + partials[jj] << std::endl; // SubPermutations.
            result.push_back(remainder[ii] + partials[jj]);
        }
    }
    
    return result;
}
*/
void PermutationsRecursiveShort(std::string remainder, std::string prefix)
{
    if(remainder.size() == 0) { // Base case.
        std::cout << prefix << std::endl;
    } else {
        for(int ii = 0; ii < remainder.size(); ++ii) {
            std::string before = remainder.substr(0, ii);
            std::string after = remainder.substr(ii + 1); // to end.

            PermutationsRecursiveShort(before + after, prefix + remainder[ii]);
        }
    }
}

int main()
{
    std::string s = "abcd";

    //PermutationsFast(s);
    PermutationsRecursiveShort(s, "");
    //std::vector<std::string> vs = PermutationsRecursive(s);
    //for(int ii = 0; ii < vs.size(); ++ii) {
    //    std::cout << vs[ii] << std::endl;
    //}

    return 0;
}