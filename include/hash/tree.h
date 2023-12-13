#pragma once

#include "treeNode.h"
#include <memory>
#include <string>

class Tree
{
public:
    Tree() = default;
    ~Tree() = default;
    Tree& operator=(Tree& other) {return *this;};
    Tree(Tree& other) {};

    void add(int);
    void addRecursive(int);
    int get(int);
    int remove(int);
    int getDepth();
    pTreeNode getRoot() { return m_root; };
    void show(pTreeNode);
    void addToNodeCount() { m_nodeCount++ ;} ;
    void subtractFromNodeCount() { m_nodeCount-- ;} ;
    int getNodeCount() { return m_nodeCount ;} ;
private:
    void _add(pTreeNode, pTreeNode);
    void _remove(pTreeNode, pTreeNode);
    void _addRecursive(pTreeNode, pTreeNode);
    int _get(pTreeNode, int);
    int _getDepth(pTreeNode);
    void _show(pTreeNode);

    pTreeNode m_root {nullptr};
    int m_nodeCount {0};
};
