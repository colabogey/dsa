#pragma once

#include "treeNode.h"
#include <memory>
#include <string>
#include <queue>
#include <list>
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
    void deleteTree();

    void collectNodeDataInOrder(pTreeNode, std::deque<int>&);
    void collectNodeDataPreOrder(pTreeNode, std::deque<int>&);
    void collectNodeDataPostOrder(pTreeNode, std::deque<int>&);
    void collectNodesInOrder(pTreeNode);

    void rebalance();
    pTreeNode inOrderSuccessor(pTreeNode);
    void levelOrder(pTreeNode, std::deque<std::list<int>>&);

  private:
    void _add(pTreeNode, pTreeNode);
    void _addRecursive(pTreeNode, pTreeNode);

    pTreeNode _remove(pTreeNode);
    pTreeNode _get(pTreeNode, int);
    int _getDepth(pTreeNode);

    void _collectNodeDataInOrder(pTreeNode, std::deque<int>&);
    void _collectNodeDataPreOrder(pTreeNode, std::deque<int>&);
    void _collectNodeDataPostOrder(pTreeNode, std::deque<int>&);
    void _collectNodesInOrder(pTreeNode);

    pTreeNode _getNodeThatIsLeftChildOfParent(pTreeNode);
    pTreeNode _getLeastValuePresent(pTreeNode);
    pTreeNode _rebalance(pTreeNode, int, int);
    void _clearNode(pTreeNode);
    bool _isNodeCleared(pTreeNode);

    pTreeNode m_root{nullptr};
    std::deque<pTreeNode> m_nodes;
};

typedef std::deque<std::list<int>> treeLevels;
