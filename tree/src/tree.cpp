
#include "tree.h"
#include <queue>

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

pTreeNode Tree::remove(int key) {
    pTreeNode ret = nullptr;
    if (m_root == nullptr) {
        return (ret);
    }

    pTreeNode node = _get(m_root, key);
    if (node != nullptr) {
        ret = _remove(node);
        subtractFromNodeCount();
    }
    return (ret);
}

pTreeNode Tree::_remove(pTreeNode curr) {
    pTreeNode prev = curr->getParent();
    if (prev == nullptr) {
        // its m_root
        // prev = curr;
    }

    if ((curr->getLeft() == nullptr) && (curr->getRight() == nullptr)) {
        // its a leaf - just zap it
        if (prev->getLeft() == curr) {
            prev->setLeft(nullptr);
        } else {
            prev->setRight(nullptr);
        }
        return (curr);
    }

    else if ((curr->getLeft() == nullptr) || curr->getRight() == nullptr) {
        // internal node with just one 'side'
        // delete the node and move its child up to take its place
        pTreeNode newNode = std::make_shared<TreeNode>();
        if (curr->getLeft() == nullptr) {
            newNode = curr->getRight();
        } else {
            newNode = curr->getLeft();
        }

        if (curr == prev->getLeft()) {
            prev->setLeft(newNode);
        } else {
            prev->setRight(newNode);
        }
        return (newNode);
    } else {
        /*
        Node to be deleted is an internal node with two children.
        Copy the contents of the inorder successor of the node to be
        deleted and delete the inorder successor.
        */
        pTreeNode successor = inOrderSuccessor(curr);

        // Compute the inorder successor
        // pTreeNode parent = nullptr;
        // pTreeNode temp = curr->getRight();
        // while (temp->getLeft() != nullptr) {
        // parent = temp;
        // temp = temp->getLeft();
        //}

        if (prev != nullptr) {
            // check if the parent of the inorder successor is the
            // curr or not (i.e. curr= the node which has the same
            // data as the given data by the user to be deleted).
            // if it isn't, then make the the left child of its
            // parent equal to the inorder successor'd right child.
            prev->setLeft(successor->getRight());
        } else {
            // if the inorder successor was the curr
            // (i.e. curr = the node which has the same data as the
            // given data by the user to be deleted), then make the
            // right child of the node to be deleted equal to the right
            // child of the inorder successor.
            curr->setRight(successor->getRight());
        }
        // set the key
        curr->setData(successor->getData());
        // we are done with successor
        // TODO: is this leaking successor
        return (successor);
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

void Tree::showInOrder(pTreeNode root) {
    if (root != nullptr) {
        _showInOrder(root);
        printf("\n");
    }
}

void Tree::_showInOrder(pTreeNode root) {
    if (root != nullptr) {
        _showInOrder(root->getLeft());
        printf("(%d) ", root->getData());
        _showInOrder(root->getRight());
    }
}

void Tree::showPreOrder(pTreeNode root) {
    if (root != nullptr) {
        _showPreOrder(root);
        printf("\n");
    }
}

void Tree::_showPreOrder(pTreeNode root) {
    if (root != nullptr) {
        printf("(%d) ", root->getData());
        _showPreOrder(root->getLeft());
        _showPreOrder(root->getRight());
    }
}

void Tree::collectInOrderData(pTreeNode root) {
    if (root != nullptr) {
        _collectInOrderData(root);
    }
}

void Tree::_collectInOrderData(pTreeNode root) {
    if (root != nullptr) {
        _collectInOrderData(root->getLeft());
        m_deque.push_back(root);
        _collectInOrderData(root->getRight());
    }
}

void Tree::rebalance() {
    _collectInOrderData(m_root);
    pTreeNode newRoot = _rebalance(m_root, 0, (m_deque.size() - 1));
    m_root = newRoot;
}

pTreeNode Tree::_rebalance(pTreeNode root, int indexLeft, int indexRight) {
    if(indexLeft > indexRight) {
        return nullptr;
    }

    int medianIndex = (indexLeft + indexRight) / 2;
    printf("m (%d), l (%d), r(%d)\n", 
        m_deque[medianIndex]->getData(), 
        m_deque[indexLeft]->getData(), 
        m_deque[indexRight]->getData());
    pTreeNode spNode = m_deque[medianIndex];
    spNode->setParent(root);
    spNode->setLeft(_rebalance(spNode, indexLeft, medianIndex - 1));
    spNode->setRight(_rebalance(spNode, medianIndex + 1, indexRight));
    return(spNode);
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

void Tree::levelOrder(pTreeNode root) {
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    std::queue<pTreeNode> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
        printf("nodeCount (%d)\n", nodeCount);

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0) {
            pTreeNode node = q.front();
            q.pop();
            printf("%d ", node->getData());
            if (node->getLeft() != nullptr) {
                q.push(node->getLeft());
            }

            if (node->getRight() != nullptr) {
                q.push(node->getRight());
            }

            nodeCount--;
        }
        printf("\n");
    }
}
