
#pragma once

#include <deque>
#include <list>
#include <memory>

class gNode {
  public:
    gNode(int node_key) { key = node_key; };
    gNode() { key = -1; };
    ~gNode() = default;

    int key{-1};
    gNode* left{NULL};
    gNode* right{NULL};
    int height{1};
};


typedef std::deque<std::list<int>> treeLevels;

class gAVLtree {
  public:
    gNode* root;
    gAVLtree() { root = NULL; }
    gNode* newNode(int);
    int height(gNode*);
    int max(int, int);
    int getBalance(gNode*);
    gNode* rightRotate(gNode*);
    gNode* leftRotate(gNode*);
    gNode* insertNode(gNode*, int);
    //gNode* deleteNode(gNode*, int);
    void levelOrder(gNode*, treeLevels&);
    void preOrder(gNode*);
};

typedef std::deque<std::list<int>> treeLevels;
