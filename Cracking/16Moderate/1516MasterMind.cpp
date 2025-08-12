#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 1516MasterMind.cpp -o hola

// Implementation - Sets

int main()
{
    std::string solution = "RGBY";
    std::string guess = "GGRR";

    int hits = 0;
    int pseudos = 0;
   
    std::set<char> solutionSet;
    std::set<char> alreadyPseudoSet;
    std::set<char> alreadyHitSet;

    int ii = 0;
    while(ii < solution.length()) { // look for hits.
        if(solution[ii] == guess[ii]) {
            auto insertion = alreadyHitSet.insert(solution[ii]);
            
            if(insertion.second == true) { // NOT exists, inserted it successfully.
                ++hits;
            }
            
        } else { // Keep track of the NO-HITS for the future pseudo-hits.
            if(alreadyHitSet.find(solution[ii]) == alreadyHitSet.end()) { // The element is NOT in the set, NOT already a hit.
                solutionSet.insert(solution[ii]);
            }
        }

        ++ii;
    }

    ii = 0;
    while(ii < guess.length()) { // look for pseudo-hits. Iteratue guess.
        if(alreadyHitSet.find(guess[ii]) != alreadyHitSet.end()) { // The element is in the set, already a hit.
            // already a hit.
        } else if(solutionSet.find(guess[ii]) != solutionSet.end()) { // The element is in the solution but NOT a hit. Pseudo.
            
            auto insertion = alreadyPseudoSet.insert(guess[ii]);
            
            if(insertion.second == true) { // NOT exists, inserted it successfully.
                ++pseudos;
            }

        }
        ++ii;
    }

    std::cout << " Hits: " << hits << "  / Pseudos: " << pseudos << std::endl;

    return 0;
}