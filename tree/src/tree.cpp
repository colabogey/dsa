
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
    if(root == nullptr)
    {
        return;
    }

    if(newNode->getData() < root->getData())
    {
        if(root->getLeft() == nullptr)
        {
            root->setLeft(newNode);
            return;
        }
        else
        {
            _addRecursive(root->getLeft(), newNode);
        }
    }
    else
    {
        if(root->getRight() == nullptr)
        {
            root->setRight(newNode);
            return;
        }
        else
        {
            _addRecursive(root->getRight(), newNode);
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
    int rVal = -1;
    if(m_root != nullptr)
    {
        rVal = _get(m_root, key);
    }
    return(rVal);
}

int Tree::_get(pTreeNode root, int key)
{
    if(root == nullptr)
    {
        return(-1);
    }

    if(root->getData() == key)
    {
        //printf("found (%d)\n", key);
        return(key);
    }

    if(key < root->getData())
    {
        //printf("visiting left (%d)\n", root->getData());
        if(root->getLeft() == nullptr)
        {
            //printf("(%d) not found\n", key);
            return(-1);
        }
        else
        {
            return(_get(root->getLeft(), key));
        }
    }
    else
    {
        //printf("visiting right (%d)\n", root->getData());
        if(root->getRight() == nullptr)
        {
            //printf("(%d) not found\n", key);
            return(-1);
        }
        else
        {
            return(_get(root->getRight(), key));
        }
    }
}

void Tree::show(pTreeNode root)
{
    if (root != nullptr) 
    {
        show(root->getLeft());
        //printf("(%d) ", root->getData());
        show(root->getRight());
    }
}
