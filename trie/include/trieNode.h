#pragma once
#include <memory>
#include <vector>

#define alphabetSize 26

class TrieNode {
  public:
    TrieNode() = default;
    virtual ~TrieNode() = default;

    TrieNode *m_root{nullptr};
    bool m_isEndOfWord{false};
    std::vector<TrieNode *> m_children{alphabetSize, nullptr};

  private:
};
