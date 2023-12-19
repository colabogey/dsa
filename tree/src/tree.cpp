
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

int Tree::remove(int key) {
    if (m_root == nullptr) {
        return (-1);
    }
    printf("remove (%d)\n", key);
    pTreeNode curr = m_root;
    pTreeNode prev = nullptr;
    while (true) {
        if (key == curr->getData()) {
            break;
        } else {
            if (key < curr->getData()) {
                // assume the key is in there
                prev = curr;
                curr = curr->getLeft();
            } else {
                prev = curr;
                curr = curr->getRight();
            }
        }
    }
    _remove(curr, prev);
    subtractFromNodeCount();
    return (key);
}

void Tree::_remove(pTreeNode curr, pTreeNode prev) {
    if (prev == nullptr) {
        // its m_root
        prev = curr;
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
        pTreeNode parent;
        pTreeNode temp;

        // Compute the inorder successor
        temp = curr->getRight();
        while (temp->getLeft() != nullptr) {
            parent = temp;
            temp = temp->getLeft();
        }

        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (parent != nullptr)
            parent->setLeft(temp->getRight());

        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data by the
        // user to be deleted), then make the
        // right child of the node to be
        // deleted equal to the right child of
        // the inorder successor.
        else
            curr->setRight(temp->getRight());

        curr->setData(temp->getData());
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
        // printf("found (%d)\n", key);
        return (root);
    }

    if (key < root->getData()) {
        // printf("visiting left (%d)\n", root->getData());
        if (root->getLeft() == nullptr) {
            // printf("(%d) not found\n", key);
            return (nullptr);
        } else {
            return (_get(root->getLeft(), key));
        }
    } else {
        // printf("visiting right (%d)\n", root->getData());
        if (root->getRight() == nullptr) {
            // printf("(%d) not found\n", key);
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

/*

wrong thinking
do a successot for a given node

and then the show thing id different
it goes by value

your brain is wrong


*/

pTreeNode Tree::inOrderSuccessor(pTreeNode node) {

    if (node == nullptr) {
        return(node);
    }

    pTreeNode successor = node;
    pTreeNode nextLeft = nullptr;
    pTreeNode nextRight = nullptr;
    if((nextRight = node->getRight()) != nullptr) {
        successor = _getLeastValuePresent(nextRight);
    } else if((nextLeft = node->getLeft()) != nullptr) {
        successor = _getNodeThatIsLeftChildOfParent(node);
    }
    return(successor);
    }

pTreeNode Tree::_getNodeThatIsLeftChildOfParent(pTreeNode node) {
    pTreeNode curr = node;
    pTreeNode parent = curr->getParent();
    while(parent != nullptr) {
        pTreeNode nextLeft = parent->getLeft();
        if(nextLeft != nullptr) {
            if(nextLeft == curr) {
                break;
            } else {
                curr = parent;
                parent = parent->getLeft();
            }
        } else {
            parent = nullptr;
            break;
        }
    }
    return(parent);
}

pTreeNode Tree::_getLeastValuePresent(pTreeNode node) {
    pTreeNode curr = node;
    while(curr != nullptr) {
        pTreeNode nextLeft = curr->getLeft();
        if(nextLeft != nullptr) {
            curr = nextLeft;
        } else {
            break;
        }
    }
    return(curr);
}
