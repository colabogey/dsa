#pragma once

#include "treeNode.h"
#include <memory>
#include <string>

class Tree {
  public:
    Tree() = default;
    ~Tree() = default;
    Tree &operator=(Tree &other) { return *this; };
    Tree(Tree &other){};

    void add(int);
    void addRecursive(int);
    pTreeNode get(int);
    pTreeNode remove(int);
    int getDepth();
    pTreeNode getRoot() { return m_root; };
    void show(pTreeNode);
    void addToNodeCount() { m_nodeCount++; };
    void subtractFromNodeCount() { m_nodeCount--; };
    int getNodeCount() { return m_nodeCount; };
    pTreeNode inOrderSuccessor(pTreeNode);

  private:
    void _add(pTreeNode, pTreeNode);
    pTreeNode _remove(pTreeNode);
    void _addRecursive(pTreeNode, pTreeNode);
    pTreeNode _get(pTreeNode, int);
    int _getDepth(pTreeNode);
    void _show(pTreeNode);
    pTreeNode _getNodeThatIsLeftChildOfParent(pTreeNode);
    pTreeNode _getLeastValuePresent(pTreeNode);

    pTreeNode m_root{nullptr};
    int m_nodeCount{0};
};
