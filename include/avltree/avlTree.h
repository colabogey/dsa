#pragma once

#include "avlTreeNode.h"
#include <deque>
#include <list>
#include <memory>
#include <queue>
#include <string>
#include <utility>

class AvlTree {
  public:
    AvlTree() = default;
    ~AvlTree() = default;
    AvlTree &operator=(AvlTree &other) { return *this; };
    AvlTree(AvlTree &other){};

    void add(int);
    pAvlTreeNode get(int);
    pAvlTreeNode remove(int);
    int getDepth();
    pAvlTreeNode getRoot() { return m_root; };
    void deleteTree();

    void collectNodeDataInOrder(pAvlTreeNode, std::deque<int> &);
    void collectNodeDataPreOrder(pAvlTreeNode, std::deque<int> &);
    void collectNodeDataPostOrder(pAvlTreeNode, std::deque<int> &);
    void collectNodesInOrder(pAvlTreeNode);

    void rebalance();
    pAvlTreeNode inOrderSuccessor(pAvlTreeNode);
    void levelOrder(pAvlTreeNode, std::deque<std::list<int>> &);

  private:
    void _add(pAvlTreeNode, pAvlTreeNode);
    pAvlTreeNode _rotate(pAvlTreeNode);
    pAvlTreeNode _rightRotate(pAvlTreeNode);
    pAvlTreeNode _leftRotate(pAvlTreeNode);
    void _preOrder(pAvlTreeNode); // TODO: get rid of this

    pAvlTreeNode _remove(pAvlTreeNode);
    pAvlTreeNode _get(pAvlTreeNode, int);
    int _getDepth(pAvlTreeNode);
    int _getBalance(pAvlTreeNode);
    int _height(pAvlTreeNode);

    void _collectNodeDataInOrder(pAvlTreeNode, std::deque<int> &);
    void _collectNodeDataPreOrder(pAvlTreeNode, std::deque<int> &);
    void _collectNodeDataPostOrder(pAvlTreeNode, std::deque<int> &);
    void _collectNodesInOrder(pAvlTreeNode);

    pAvlTreeNode _getNodeThatIsLeftChildOfParent(pAvlTreeNode);
    pAvlTreeNode _getLeastValuePresent(pAvlTreeNode);
    pAvlTreeNode _rebalance(pAvlTreeNode, int, int);
    void _clearNode(pAvlTreeNode);
    bool _isNodeCleared(pAvlTreeNode);

    pAvlTreeNode m_root{nullptr};
    std::deque<pAvlTreeNode> m_nodes;
};

typedef std::deque<std::list<int>> treeLevels;
