
#include "tree.h"

void Tree::addRecursive(int data) {
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if (m_root == nullptr) {
        m_root = newItem;
    } else {
        _addRecursive(m_root, newItem);
    }
    addToNodeCount();
}

void Tree::add(int data) {
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if (m_root == nullptr) {
        m_root = newItem;
    } else {
        _add(m_root, newItem);
    }
    addToNodeCount();
}

void Tree::_addRecursive(pTreeNode root, pTreeNode newNode) {
    if (root == nullptr) {
        return;
    }

    if (newNode->getData() < root->getData()) {
        if (root->getLeft() == nullptr) {
            root->setLeft(newNode);
            newNode->setParent(root);
            return;
        } else {
            _addRecursive(root->getLeft(), newNode);
        }
    } else {
        if (root->getRight() == nullptr) {
            root->setRight(newNode);
            newNode->setParent(root);
            return;
        } else {
            _addRecursive(root->getRight(), newNode);
        }
    }
}

void Tree::_add(pTreeNode root, pTreeNode newNode) {

    pTreeNode curr = root;
    while (true) {
        if (newNode->getData() < curr->getData()) {
            // go left
            if (curr->getLeft() == nullptr) {
                curr->setLeft(newNode);
                newNode->setParent(curr);
                break;
            }
            curr = curr->getLeft();
        } else {
            // go right
            if (curr->getRight() == nullptr) {
                curr->setRight(newNode);
                newNode->setParent(curr);
                break;
            }
            curr = curr->getRight();
        }
    }
}

/*

TODO: now that you have a prev pointer
      and a get thet returns a node
      this can be simplified

*/
pTreeNode Tree::remove(int key) {
    if (m_root == nullptr) {
        return (nullptr);
    }

    printf("remove (%d)\n", key);
    pTreeNode node =_get(m_root, key);
    if(node != nullptr) {
        _remove(node);
        subtractFromNodeCount();
    }
    return (node);
}

/*

: understand this


*/
void Tree::_remove(pTreeNode node) {
    pTreeNode curr = node;
    pTreeNode prev = node->getParent();
    if (prev == nullptr) {
        // its m_root
        //prev = curr;
    }

    if ((curr->getLeft() == nullptr) && (curr->getRight() == nullptr)) {
        // its a leaf - just zap it
        if (prev->getLeft() == curr) {
            prev->setLeft(nullptr);
        } else {
            prev->setRight(nullptr);
        }
    }

    else if ((curr->getLeft() == nullptr) || curr->getRight() == nullptr) {
        // internal node with just one 'side'
        if (curr->getLeft() != nullptr) {
            if (curr = prev->getLeft()) {
                prev->setLeft(curr->getLeft());
            }
        } else {
            if (curr = prev->getRight()) {
                prev->setRight(curr->getRight());
            }
        }
    } else {
        pTreeNode successor = inOrderSuccessor(curr);;

        // Compute the inorder successor
        //pTreeNode parent = nullptr;
        //pTreeNode temp = curr->getRight();
        //while (temp->getLeft() != nullptr) {
            //parent = temp;
            //temp = temp->getLeft();
        //}

        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (prev != nullptr)
            prev->setLeft(successor->getRight());

        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data by the
        // user to be deleted), then make the
        // right child of the node to be
        // deleted equal to the right child of
        // the inorder successor.
        else
            curr->setRight(successor->getRight());

        curr->setData(successor->getData());
    }
}

pTreeNode Tree::get(int key) {
    pTreeNode node = nullptr;
    if (m_root != nullptr) {
        node = _get(m_root, key);
    }
    return (node);
}

pTreeNode Tree::_get(pTreeNode root, int key) {
    if (root == nullptr) {
        return (root);
    }

    if (root->getData() == key) {
        return (root);
    }

    if (key < root->getData()) {
        if (root->getLeft() == nullptr) {
            return (nullptr);
        } else {
            return (_get(root->getLeft(), key));
        }
    } else {
        if (root->getRight() == nullptr) {
            return (nullptr);
        } else {
            return (_get(root->getRight(), key));
        }
    }
}

void Tree::show(pTreeNode root) {
    if (root != nullptr) {
        _show(root);
        printf("\n");
    }
}

void Tree::_show(pTreeNode root) {
    if (root != nullptr) {
        _show(root->getLeft());
        printf("(%d) ", root->getData());
        show(root->getRight());
    }
}

int Tree::getDepth() {
    int i = _getDepth(m_root);
    return (i);
}

int Tree::_getDepth(pTreeNode root) {
    if (root == nullptr) {
        return (0);
    }
    int lVal = _getDepth(root->getLeft());
    int rVal = _getDepth(root->getRight());
    if (lVal > rVal) {
        return (lVal + 1);
    } else {
        return (rVal + 1);
    }
}

pTreeNode Tree::inOrderSuccessor(pTreeNode node) {

    if (node == nullptr) {
        return (node);
    }

    pTreeNode successor = node;
    pTreeNode nextLeft = nullptr;
    pTreeNode nextRight = nullptr;
    if ((nextRight = node->getRight()) != nullptr) {
        successor = _getLeastValuePresent(nextRight);
    } else {
        successor = _getNodeThatIsLeftChildOfParent(node);
    }
    return (successor);
}

pTreeNode Tree::_getNodeThatIsLeftChildOfParent(pTreeNode node) {
    pTreeNode parent = node->getParent();
    while ((parent != nullptr) && (node == parent->getRight())) {
        node = parent;
        parent = parent->getParent();
    }
    return (parent);
}

pTreeNode Tree::_getLeastValuePresent(pTreeNode node) {
    pTreeNode curr = node;
    while (curr->getLeft() != nullptr) {
        curr = curr->getLeft();
    }
    return (curr);
}
