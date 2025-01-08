#include <iostream>
#include <map>

/*
Can I arange the string to be a palindrome ?

Process thought:
  - BruteForce, all posible combinations.
    Time complexity: O(n^2) ?

  - map. All chars must be of frequency even. Exception of one char if the string is odd.
    - Iterate string, build map.
    - Iterate and check map.
    Time complexity: O(n)

    Posible optimization: See number of counts as iterating the first vector (auxiliar vector needed).
                            Use bits to be more space friendly.
*/

bool PP(const std::string &s) 
{
    bool isStringEven = (s.size() % 2 == 0);

    std::map<char, int> m; // key=character, value=freq.
    for(int ii = 0; ii < s.size(); ++ii) {
        m[s[ii]]++;
    }

    int itNumber = 0;
    int oddFreqCounts = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        //std::cout << it->first << " is " << it->second << std::endl;

        if(it->second % 2 == 0) { // even.

        } else { // odd.
            if(!isStringEven) { // Check just one odd
                ++oddFreqCounts;
                if(oddFreqCounts > 1) {
                    return false;
                }
            } else {
                return false;
            }
        }

        ++itNumber;
    }

    return true;
}

void print(const std::string &s)
{
    if(PP(s)) {
        std::cout << s << " is a PalindromePermutation." << std::endl;
    } else {
        std::cout << s << " is NOT a PalindromePermutation." << std::endl;
    }
}

int main() 
{
    std::string s1 = "hola";         // -
    std::string s2 = "tactcoa";      // tacocat
    std::string s3 = "tazctcoa";     // -
    std::string s4 = "taoctcoaoaa";  // aatcoooctaa
    print(s1);
    print(s2);
    print(s3);
    print(s4);

    return 0;
}