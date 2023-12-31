
#include "../include/tree.h"

void Tree::addRecursive(int data) {
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if (m_root == nullptr) {
        m_root = newItem;
    } else {
        _addRecursive(m_root, newItem);
    }
}

void Tree::add(int data) {
    pTreeNode newItem = std::make_shared<TreeNode>();
    newItem->setData(data);
    if (m_root == nullptr) {
        m_root = newItem;
    } else {
        _add(m_root, newItem);
    }
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
    }
    return (ret);
}

pTreeNode Tree::_remove(pTreeNode curr) {
    if(_isNodeCleared(curr)) {
        return(curr);
    }

    pTreeNode prev = curr->getParent();

    if ((curr->getLeft() == nullptr) && (curr->getRight() == nullptr)) {
        // its a leaf - just zap it
        if (prev->getLeft() == curr) {
            prev->setLeft(nullptr);
        } else {
            prev->setRight(nullptr);
        }
        _clearNode(curr);
        return (curr);
    } else if (curr->getLeft() == nullptr) {
        // internal node with just one 'side'
        // Right side  only
        // delete the node and move its child up to take its place
        if(prev->getLeft() == curr) {
            prev->setLeft(curr->getRight());
        } else {
            prev->setRight(curr->getRight());
        }
        _clearNode(curr);
        return(curr);
    } else if (curr->getRight() == nullptr) {
        // internal node with just one 'side'
        // left side only
        // delete the node and move its child up to take its place
        if(prev->getLeft() == curr) {
            prev->setLeft(curr->getLeft());
        } else {
            prev->setRight(curr->getLeft());
        }
        _clearNode(curr);
        return(curr);
    } else {
        /*
        Node to be deleted is an internal node with two children.
        Copy the contents of the inorder successor of the node to be
            deleted and delete the inorder successor.
        The onOrderSuccessor icall works because there is a right tree, so it will find the minimum
            value in the right tree.
        */
        int currData = curr->getData();
        pTreeNode successor = inOrderSuccessor(curr);
        curr->setData(successor->getData());
        // successor is a minimum
        // so it does not have a left tree
        // so it is an internal node with just one side
        // we already know how to do that so the recursive call is the most straightforward approach.
        successor->setData(currData);    // simply swapped nodes
        _remove(successor);
        _clearNode(successor);
        // we are done with successor
        // TODO: is this leaking successor
        return (successor);
    }
}

void Tree::_clearNode(pTreeNode node) {
    node->setLeft(nullptr);
    node->setRight(nullptr);
    node->setParent(nullptr);
}

bool Tree::_isNodeCleared(pTreeNode node) {
    bool bRet = false;
    if(node->getLeft() == nullptr && node->getRight() == nullptr && node->getParent() == nullptr) {
        bRet = true;
    }
    return bRet;
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
        return (nullptr);
    }

    if (root->getData() == key) {
        return (root);
    }

    if (key < root->getData()) {
        return(_get(root->getLeft(), key));
    } else {
        return(_get(root->getRight(), key));
    }
}

void Tree::collectNodeDataInOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        _collectNodeDataInOrder(root, q);
    }
}

void Tree::_collectNodeDataInOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        _collectNodeDataInOrder(root->getLeft(), q);
        q.push_back(root->getData());
        _collectNodeDataInOrder(root->getRight(), q);
    }
}

void Tree::collectNodeDataPostOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        _collectNodeDataPostOrder(root, q);
    }
}

void Tree::_collectNodeDataPostOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        _collectNodeDataPostOrder(root->getLeft(), q);
        _collectNodeDataPostOrder(root->getRight(), q);
        q.push_back(root->getData());
    }
}

void Tree::collectNodeDataPreOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        _collectNodeDataPreOrder(root, q);
    }
}

void Tree::_collectNodeDataPreOrder(pTreeNode root, std::deque<int>& q) {
    if (root != nullptr) {
        q.push_back(root->getData());
        _collectNodeDataPreOrder(root->getLeft(), q);
        _collectNodeDataPreOrder(root->getRight(), q);
    }
}

void Tree::collectNodesInOrder(pTreeNode root) {
    if (root != nullptr) {
        _collectNodesInOrder(root);
    }
}

void Tree::_collectNodesInOrder(pTreeNode root) {
    if (root != nullptr) {
        _collectNodesInOrder(root->getLeft());
        m_nodes.push_back(root);
        _collectNodesInOrder(root->getRight());
    }
}

void Tree::rebalance() {
    _collectNodesInOrder(m_root);
    pTreeNode newRoot = _rebalance(m_root, 0, (m_nodes.size() - 1));
    m_root = newRoot;
    m_nodes.clear();
}

pTreeNode Tree::_rebalance(pTreeNode root, int indexLeft, int indexRight) {
    if(indexLeft > indexRight) {
        return nullptr;
    }

    int medianIndex = (indexLeft + indexRight) / 2;
    //printf("m (%d), l (%d), r(%d)\n",
        //m_nodes[medianIndex]->getData(),
        //m_nodes[indexLeft]->getData(),
        //m_nodes[indexRight]->getData());
    pTreeNode spNode = m_nodes[medianIndex];
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

void Tree::levelOrder(pTreeNode root, treeLevels& levels) {
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
        //printf("nodeCount (%d)\n", nodeCount);
        std::list<int> nodesInLevel;

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0) {
            pTreeNode node = q.front();
            q.pop();
            nodesInLevel.push_back(node->getData());
            //printf("%d ", node->getData());
            if (node->getLeft() != nullptr) {
                q.push(node->getLeft());
            }

            if (node->getRight() != nullptr) {
                q.push(node->getRight());
            }

            nodeCount--;
        }
        //printf("\n");
        levels.push_back(nodesInLevel);
    }
}
