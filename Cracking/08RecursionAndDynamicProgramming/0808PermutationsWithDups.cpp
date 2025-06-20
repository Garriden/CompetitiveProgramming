#include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>

// g++ -std=c++20 0808PermutationsWithDups.cpp -o hola

// Just preprocess the string with a set.

void PermutationsFast(std::string s)
{
    do {
        std::cout << s << std::endl;
    } while(std::next_permutation(s.begin(), s.end()));
}

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
    std::string s = "abcdaabbabdba";
    std::string s2 = "";

    std::set<int> mySet;
    for(int ii = 0; ii < s.size(); ++ii) {
        if(mySet.insert(s[ii]).second) {
            s2 += s[ii];
        }
    }
    

    //PermutationsFast(s);
    PermutationsRecursiveShort(s2, "");
    //PermutationsUniqueRecursive(s, "");
    //std::vector<std::string> vs = PermutationsRecursive(s);
    //for(int ii = 0; ii < vs.size(); ++ii) {
    //    std::cout << vs[ii] << std::endl;
    //}

    return 0;
}