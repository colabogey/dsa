#pragma once

#include "treeNode.h"
#include <memory>
#include <string>
#include <queue>
#include <deque>
#include <utility>

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
    void showInOrder(pTreeNode);
    void showPreOrder(pTreeNode);
    void collectInOrderData(pTreeNode);
    void rebalance();
    void addToNodeCount() { m_nodeCount++; };
    void subtractFromNodeCount() { m_nodeCount--; };
    int getNodeCount() { return m_nodeCount; };
    pTreeNode inOrderSuccessor(pTreeNode);
    void levelOrder(pTreeNode);

  private:
    void _add(pTreeNode, pTreeNode);
    pTreeNode _remove(pTreeNode);
    void _addRecursive(pTreeNode, pTreeNode);
    pTreeNode _get(pTreeNode, int);
    int _getDepth(pTreeNode);
    void _showInOrder(pTreeNode);
    void _showPreOrder(pTreeNode);
    void _collectInOrderData(pTreeNode);
    pTreeNode _getNodeThatIsLeftChildOfParent(pTreeNode);
    pTreeNode _getLeastValuePresent(pTreeNode);
    pTreeNode _rebalance(pTreeNode, int, int);

    pTreeNode m_root{nullptr};
    int m_nodeCount{0};
    std::deque<pTreeNode> m_deque;
};
