
#include "tree.h"
#include "tree.h"

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
        _add(newItem, data);
    }
    addToNodeCount();
}

void Tree::_add(pTreeNode newNode, int key)
{

    printf("_add (%d)\n", key);
    if(m_root == nullptr) {
        m_root = newNode;
        return;
    }

    pTreeNode curr = m_root;
    while(true)
    {
        if(key < curr->getData())
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
