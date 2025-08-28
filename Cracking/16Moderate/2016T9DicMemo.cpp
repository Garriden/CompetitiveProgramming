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

// g++ -std=c++17 2016T9DicMemo.cpp -o hola

// Precompute (memorization) the entire dicctionary before doing the proper exercise.
//  1- Compute all words in the language. APPLE -> "27753"
//  2- Store it in a map <digits, words>. 8733 -> "used", "tree".

struct LettersToDigits {
    std::unordered_map<char, char> mapping;

    // Constructor.
    LettersToDigits() {
        mapping['a'] = '2'; mapping['b'] = '2'; mapping['c'] = '2';
        mapping['d'] = '3'; mapping['e'] = '3'; mapping['f'] = '3';
        mapping['g'] = '4'; mapping['h'] = '4'; mapping['i'] = '4';
        mapping['j'] = '5'; mapping['k'] = '5'; mapping['l'] = '5';
        mapping['m'] = '6'; mapping['n'] = '6'; mapping['o'] = '6';
        mapping['p'] = '7'; mapping['q'] = '7'; mapping['r'] = '7'; mapping['s'] = '7';
        mapping['t'] = '8'; mapping['u'] = '8'; mapping['v'] = '8';
        mapping['w'] = '9'; mapping['x'] = '9'; mapping['y'] = '9'; mapping['z'] = '9';
    }
};

int main()
{
    std::vector<std::string> words = {"hola", "bondia", "caracola", "pepe", "tree", "troo", "ucam", "usaa", "pico", "caca", "used"};
    std::unordered_map<std::string, std::vector<std::string> > mapDigitStrings;
    LettersToDigits translator;

    //  1- Compute all words in the language. APPLE -> "27753"
    for(int ii = 0; ii < words.size(); ++ii) {
        std::string word = words[ii];
        std::string digits = "";

        for(int jj = 0; jj < word.size(); ++jj) {
            char letter = word[jj];
            digits += translator.mapping[letter];
        }

        //  2- Store it in a map <digits, words>. 8733 -> "used", "tree".

        /*
        std::vector<std::string> v;
        // if some string already on the value, don't lose the data before
        if(mapDigitStrings.count(digits) > 0) {
            v = mapDigitStrings[digits];
        }
        v.push_back(word);
        mapDigitStrings[digits] = v;
        */
        //std::cout << "digits: " << digits << " / word: " << word << std::endl;
        mapDigitStrings[digits].push_back(word);
        digits = "";
    }

    std::vector<std::string> res = mapDigitStrings["8733"];
    for(int ii = 0; ii < res.size(); ++ii) {
        std::cout << res[ii] << " ";
    } std::cout << std::endl;

    return 0;
}