#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <memory>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    std::unique_ptr<TrieNode> children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie {
public:
    Trie();

    bool Search(const std::string &s);
    void Insert(const std::string &s);
    std::vector<std::string> FindMobileWords(const std::string &s);
private:
    
    std::string GetWord(TrieNode *node);

    std::unique_ptr<TrieNode> _root;
};


#endif