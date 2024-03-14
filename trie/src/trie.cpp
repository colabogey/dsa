// C++ implementation of search and insert
// operations on Trie
#include "trie.h"
#include <bits/stdc++.h>

// trie node
// Returns new trie node (initialized to NULLs)
TrieNode *Trie::getNode(void) {
    TrieNode *pNode = new TrieNode;
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void Trie::insert(TrieNode *root, std::string key) {
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->m_children[index])
            pCrawl->m_children[index] = getNode();

        pCrawl = pCrawl->m_children[index];
    }

    // mark last node as leaf
    pCrawl->m_isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool Trie::search(TrieNode *root, std::string key) {
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->m_children[index])
            return false;

        pCrawl = pCrawl->m_children[index];
    }

    return (pCrawl->m_isEndOfWord);
}

// Driver
int Trie::trie_main() {
    // Input keys (use only 'a' through 'z'
    // and lower case)
    std::string keys[] = {"the", "a",  "there", "answer",
                          "any", "by", "bye",   "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    char output[][32] = {"Not present in trie", "Present in trie"};

    // Search for different keys
    std::cout << "the"
              << " --- " << output[search(root, "the")] << std::endl;
    std::cout << "these"
              << " --- " << output[search(root, "these")] << std::endl;
    std::cout << "their"
              << " --- " << output[search(root, "their")] << std::endl;
    std::cout << "thaw"
              << " --- " << output[search(root, "thaw")] << std::endl;
    return 0;
}
