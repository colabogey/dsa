
#include "tree.h"
#include "tree.h"

void Tree::addRecursive(int data)
{
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if(m_root == nullptr)
    {
        m_root = newItem;
    }
    else
    {
        _addRecursive(m_root, newItem);
    }
    addToNodeCount();
}

void Tree::add(int data)
{
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if(m_root == nullptr)
    {
        m_root = newItem;
    }
    else
    {
        _add(m_root, newItem);
    }
    addToNodeCount();
}

void Tree::_addRecursive(pTreeNode root, pTreeNode newNode)
{
    pTreeNode newRoot = root;
    if(root == nullptr)
    {
        return;
    }

    if(newNode->getData() < newRoot->getData())
    {
        if(newRoot->getLeft() == nullptr)
        {
            newRoot->setLeft(newNode);
            return;
        }
        else
        {
            _addRecursive(newRoot->getLeft(), newNode);
        }
    }
    else
    {
        if(newRoot->getRight() == nullptr)
        {
            newRoot->setRight(newNode);
            return;
        }
        else
        {
            _addRecursive(newRoot->getRight(), newNode);
        }
    }
}

void Tree::_add(pTreeNode root, pTreeNode newNode)
{

    pTreeNode curr = root;
    while(true)
    {
        if(newNode->getData() < curr->getData())
        {
        // go left
            if(curr->getLeft() == nullptr)
            {
                curr->setLeft(newNode);
                break;
            }
            curr = curr->getLeft();
        }
        else
        {
        // go right
            if(curr->getRight() == nullptr)
            {
                curr->setRight(newNode);
                break;
            }
            curr = curr->getRight();
        }
    }
}

int Tree::remove(int key)
{
   return(0);
}

int Tree::get(int key)
{
   return(0);
}

void Tree::show(pTreeNode root)
{
    if (root != nullptr) 
    {
        show(root->getLeft());
        printf("(%d) ", root->getData());
        show(root->getRight());
    }
}
