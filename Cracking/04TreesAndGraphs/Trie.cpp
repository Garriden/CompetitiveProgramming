#include "Trie.hpp"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>

Trie::Trie() : _root{std::make_unique<TrieNode>()} {}

struct DigitToLetters {
    std::unordered_map<int, std::vector<char> > mapping;

    // Constructor.
    DigitToLetters() {
        mapping[2] = {'a','b','c'};
        mapping[3] = {'d','e','f'};
        mapping[4] = {'g','h','i'};
        mapping[5] = {'j','k','l'};
        mapping[6] = {'m','n','o'};
        mapping[7] = {'p','q','r','s'};
        mapping[8] = {'t','u','v'};
        mapping[9] = {'w','x','y','z'};
    }
};

void Trie::Insert(const std::string &s)
{
    TrieNode *node = _root.get();
    for(int ii = 0; ii < s.size(); ++ii) {
        int trieIndex = s[ii] - 'a';

        if(!node->children[trieIndex]) { // Word doesn't exist.
            // Create new node.
            node->children[trieIndex] = std::make_unique<TrieNode>();
        }

        node = node->children[trieIndex].get();
    }

    node->isEndOfWord = true;
}

bool Trie::Search(const std::string &s)
{
    TrieNode *node = _root.get();

    for(int ii = 0; ii < s.size(); ++ii) {
        int trieIndex = s[ii] - 'a';
        //std::cout << trieIndex + 'a'; 

        if(!node->children[trieIndex]) { // Word doesn't exist.
            return false;
        }
        
        node = node->children[trieIndex].get();
    }

    //std::cout << "Search: " << node->isEndOfWord << std::endl;
    return node->isEndOfWord;
}

std::vector<std::string> Trie::FindMobileWords(const std::string &s)
{
    std::queue<std::string> words;
    std::queue<TrieNode*> nodes;
    DigitToLetters translator;
    nodes.push(_root.get());
    words.push("");

    for(int ii = 0; ii < s.size(); ++ii) {
        std::vector<char> vInput = translator.mapping[s[ii] - '0']; // 2 -> 'a','b','c'.
        std::queue<TrieNode*> nodesAux = nodes;

        while(!nodesAux.empty()) {
            for(int jj = 0; jj < vInput.size(); ++jj) { // The four letters in the pad.
                int trieIndex = vInput[jj] - 'a';
                //std::cout << vInput[jj] << " TrieIndex: " << trieIndex << std::endl;

                if(nodesAux.front()->children[trieIndex]) { // exists.
                    // new possible node ?
                    nodes.push(nodesAux.front()->children[trieIndex].get());
                    words.push(words.front() + vInput[jj]);
                }
            }
            nodesAux.pop();
            nodes.pop();
            words.pop();
        }
    }

    std::vector<std::string> res = {};
    while(!words.empty()) {
        std::string word = words.front();
        std::cout << word << std::endl;
        if(Search(word)) {
            res.push_back(word);
            //std::cout << word << std::endl;
        }
        words.pop();
    }

    return res;
}