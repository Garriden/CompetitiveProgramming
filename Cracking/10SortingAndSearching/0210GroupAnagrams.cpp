#include <iostream>
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

// g++ -std=c++20 0210GroupAnagrams.cpp -o hola

// BF: Sort the vector. For every string, sort the string.
// Time complexity: (n*log(n)) * (s*log(s))

// Using multimap: a map with repeated keys. Key = anagram, Value = original string.
// Time complexity: n * s*log(s)

// Substitute a multimap for a map where the value is a string of strings.

// Using multimap.
void GroupAnagrams(std::vector<std::string> &v)
{
    std::multimap<std::string, std::string> hashMap; // Key = anagram, Value = original string.

    // Build the multimap so all the anagrams would be next each other.
    for(int ii = 0; ii < v.size(); ++ii) {
        std::string anagram = v[ii];
        std::sort(anagram.begin(), anagram.end());

        //hashMap[anagram] = v[ii];
        hashMap.insert({anagram, v[ii]});
    }

    int index = 0;
    // Translate multimap into vector.
    for(auto pair : hashMap) {
        std::cout << pair.first << " - " << pair.second << std::endl;
        v[index++] = pair.second;
    }
}

// Using a vector inside the map.
void GroupAnagramsVectorInsideMap(std::vector<std::string> &v) {
    std::map<std::string, std::vector<std::string> > anagramGroups;

    for (const std::string& str : v) {
        std::string anagram = str;
        std::sort(anagram.begin(), anagram.end());
        anagramGroups[anagram].push_back(str); // Append to the vector
    }

    int index = 0;
    for (const auto& pair : anagramGroups) {
        for (const std::string& ana : pair.second) {
            v[index++] = ana;
        }
    }
}

int main()
{
    std::vector<std::string> v = {"hola", "aloh", "bondia", "pepe", "epep", "peep"};

    GroupAnagrams(v);

    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    } std::cout << std::endl;

    return 0;
}