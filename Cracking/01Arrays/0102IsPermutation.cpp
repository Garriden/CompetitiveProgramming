#include <map>
#include <iostream>

/*
Process thought:
  - Brute force: Check every char from one string to another.
    Time complexity: O(n^2)

  - Order it? And then iterate/check.
    Time complexity: O(n log(n))

  - Use a map. key = char, value = freq.
    - Iterate s1, build map.
    - Iterate s2, check map.
    Time complexity: O(n)
*/

bool isPermutation(const std::string &s1, const std::string &s2) 
{
    if(s1.size() != s2.size()) {
        return false;
    }

    std::map<char, int> dicc;

    for(int ii = 0; ii < s1.length(); ++ii) {
        dicc[s1[ii]]++;
    }

    for(int ii = 0; ii < s2.length(); ++ii) {
        dicc[s2[ii]]--;
        if(dicc[s2[ii]] == 0) {
            dicc.erase(s2[ii]);
        }
    }

    if(dicc.size() == 0) {
        return true;
    }

    return false;
}

void print(const std::string &s1, const std::string &s2)
{
    if(isPermutation(s1, s2)) {
        std::cout << s1 << " - " << s2 << " is a Permutation." << std::endl;
    } else {
        std::cout << s1 << " - " << s2 << " is NOT a Permutation." << std::endl;
    }
}

bool isUniqueWithoutDataStructure(const std::string &s)
{

    return true;
}

int main() 
{
    std::string s1 = "bondia";
    std::string s2 = "bonanit";
    print(s1, s2);

    s1 = "aabc";
    s2 = "baca";
    print(s1, s2);

    return 0;
}