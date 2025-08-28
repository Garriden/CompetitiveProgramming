#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <queue>
#include "../04TreesAndGraphs/Trie.hpp"

// g++ -std=c++17 2016T9Trie.cpp ../04TreesAndGraphs/Trie.cpp -o hola

// Trie: Search and Insert a Word: O(L) Where L is the length of the word.
// In this exercise, the Trie data structure might NOT be the best approach
//  because I need to constantly iterate the trie while translating the mobile pad code.

int main()
{
    Trie trie;

    std::vector<std::string> words = {"hola", "bondia", "caracola", "pepe", "tree", "troo", "ucam", "usaa", "pico", "caca", "used"};

    for(int ii = 0; ii < words.size(); ++ii) {
        trie.Insert(words[ii]);
    }

    std::cout << trie.Search("hola") << std::endl;
    std::cout << trie.Search("Cucurella") << std::endl;

    std::string input = "8733";
    trie.FindMobileWords(input);

    return 0;
}