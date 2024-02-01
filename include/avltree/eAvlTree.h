#pragma once

#include <deque>
#include <list>
#include <memory>

class Node {
  public:
    int value;

    Node *left_child;
    Node *right_child;

    Node() {
        value = 0;
        left_child = NULL;
        right_child = NULL;
    }

    Node(int v) {
        value = v;
        left_child = NULL;
        right_child = NULL;
    }
};

typedef std::deque<std::list<int>> treeLevels;

class AVLtree {
  public:
    Node *root;
    AVLtree() { root = NULL; }
    int height(Node *);
    int getBalanceFactor(Node *);
    Node *rightRotate(Node *);
    Node *leftRotate(Node *);
    Node *balanceTree(int, Node *);
    Node *insertNode(Node *, Node *);
    Node *deleteNode(Node *, int);
    void levelOrder(Node *, treeLevels &);
    void prettyPrintTree(Node *, int);
    void _preOrder(Node *);
};

typedef std::deque<std::list<int>> treeLevels;
