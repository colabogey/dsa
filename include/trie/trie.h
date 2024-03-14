#pragma once

#include "trieNode.h"

class Trie {
  public:
    Trie() = default;
    ~Trie() = default;
    Trie &operator=(Trie &other) { return *this; };
    Trie(Trie &other){};

    int trie_main();
    TrieNode *getRoot() { return m_root; };
    TrieNode *getNode();
    void insert(TrieNode *, std::string);
    bool search(TrieNode *, std::string);

  private:
    TrieNode *m_root{nullptr};
};
