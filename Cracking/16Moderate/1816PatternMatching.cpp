#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <limits.h>

// g++ 1816PatternMatching.cpp -o hola

// Needs a set to check if exists past chars. O(n * log n)
// Potencially watch all chars before O(n^2)

bool Pattern(const std::string &value, const std::string &pattern)
{
    std::string myPattern = "";

    if(pattern == "a" || pattern == "b") {
        return true;
    } else if(pattern == "ab" || pattern == "ba") {
        if(value.size() > 1) {
            return true;
        } else {
            return false;
        }
    } else {
        std::set<char> mySet;
        std::vector<char> v;
        std::set<char> mySetB;
        std::vector<char> vB;
        bool patternA = true;
        bool patternB = true;
        int jj = 0;

        for(int ii = 0; ii < value.size(); ++ii) { // pattern a.
            if(mySet.count(value[ii]) > 0) {
                if(patternA) {
                    myPattern.push_back('a');
                    patternA = false;
                }

                if(value[ii] == v[jj++]) {
                    // gut.
                    if(jj == v.size()) {
                        myPattern.push_back('a');
                    }
                } else { // start new pattern.
                    jj = 0;
                    if(value[ii] == v[jj++]) {
                        // gut.
                    } else {
                        std::cout << "mec." << std::endl;
                        return false;
                    }
                }
            } else if(mySetB.count(value[ii]) > 0) { // pattern b

                if(value[ii] == vB[jj++]) {
                    // gut.
                    if(jj == vB.size()) {
                        myPattern.push_back('b');
                    }
                } else { // start new pattern.
                    jj = 0;
                    if(value[ii] == vB[jj++]) {
                        // gut.
                    } else {
                        std::cout << "mec B." << std::endl;
                        return false;
                    }
                }
                
            } else {
                jj = 0;
                if(patternA) {
                    mySet.insert(value[ii]);
                    v.push_back(value[ii]);
                } else {
                    if(patternB) {
                        myPattern.push_back('b');
                        patternB = false;
                    }
                    mySetB.insert(value[ii]);
                    vB.push_back(value[ii]);
                }
            }
        }
    }

    //std::cout << myPattern << std::endl;

    if(myPattern == pattern) {
        return true;
    } else if(myPattern.find(pattern) != std::string::npos) { // contains substring.
        return true;
    }

    return false;
}

int main()
{
    std::string value = "catcatgocatgo";
    std::string pattern1 = "a";
    std::string pattern2 = "b";
    std::string pattern3 = "ab";
    std::string pattern4 = "ba";
    std::string pattern5 = "aab";
    std::string pattern6 = "aabab";

    std::string pattern7 = "aababa";
    std::string pattern8 = "aaab";

    std::cout << Pattern(value, pattern1) << std::endl;
    std::cout << Pattern(value, pattern2) << std::endl;
    std::cout << Pattern(value, pattern3) << std::endl;
    std::cout << Pattern(value, pattern4) << std::endl;
    std::cout << Pattern(value, pattern5) << std::endl;
    std::cout << Pattern(value, pattern6) << std::endl;

    std::cout << Pattern(value, pattern7) << std::endl;
    std::cout << Pattern(value, pattern8) << std::endl;

    return 0;
}