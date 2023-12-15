
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
            return;
        } else {
            _addRecursive(root->getLeft(), newNode);
        }
    } else {
        if (root->getRight() == nullptr) {
            root->setRight(newNode);
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
                break;
            }
            curr = curr->getLeft();
        } else {
            // go right
            if (curr->getRight() == nullptr) {
                curr->setRight(newNode);
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

int Tree::get(int key) {
    int rVal = -1;
    if (m_root != nullptr) {
        rVal = _get(m_root, key);
    }
    return (rVal);
}

int Tree::_get(pTreeNode root, int key) {
    if (root == nullptr) {
        return (-1);
    }

    if (root->getData() == key) {
        // printf("found (%d)\n", key);
        return (key);
    }

    if (key < root->getData()) {
        // printf("visiting left (%d)\n", root->getData());
        if (root->getLeft() == nullptr) {
            // printf("(%d) not found\n", key);
            return (-1);
        } else {
            return (_get(root->getLeft(), key));
        }
    } else {
        // printf("visiting right (%d)\n", root->getData());
        if (root->getRight() == nullptr) {
            // printf("(%d) not found\n", key);
            return (-1);
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
