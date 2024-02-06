
#include "../include/tree.h"

bool Tree::isBalanced(pTreeNode root) {
    bool ret = true;
    int balance = _getBalanceFactor(root);
    if(balance != 1 && balance != 0 && balance != -1) {
        ret = false;
    }
    return ret;
}

pTreeNode Tree::add(pTreeNode root, pTreeNode parent, int data) {
    pTreeNode added = _add(root, parent, data);
    return(added);
}

pTreeNode Tree::_add(pTreeNode root, pTreeNode parent, int data) {
    if (root == nullptr) {
        pTreeNode newNode = std::make_shared<TreeNode>(data, parent);
        return(newNode);
    }

    if (data < root->getData()) {
        root->m_left = add(root->m_left, root, data);
    } else if (data > root->getData()) {
        root->m_right = add(root->m_right, root, data);
    } else {
        // keys are equal
        return(root);
    }

    int balance = _getBalanceFactor(root);
    if(balance != 1 && balance != 0 && balance != -1) {
        root = _balanceTree(root, balance);
    }
    // left heavy is positive
    // right heavy is negative
    return(root);
}

pTreeNode Tree::_balanceTree(pTreeNode unbalanced_node, int balance_factor) {
    // out of balance
    // 2 means left heavy
    // -2 means right heavy
    if (balance_factor > 1) {
        // left-left imbalance
        if (_getBalanceFactor(unbalanced_node->m_left) >= 0) {
            unbalanced_node = _rightRotate(unbalanced_node);
            return unbalanced_node;
        }

        // left-right imbalance
        else if (_getBalanceFactor(unbalanced_node->m_left) == -1) {
            unbalanced_node->m_left =
                _leftRotate(unbalanced_node->m_left);
            unbalanced_node = _rightRotate(unbalanced_node);
            return unbalanced_node;
        }
    }

    if (balance_factor < -1) {
        // right-right imbalance
        if (_getBalanceFactor(unbalanced_node->m_right) <= -0) {
            unbalanced_node = _leftRotate(unbalanced_node);
            return unbalanced_node;
        }

        // right-left imbalance
        else if (_getBalanceFactor(unbalanced_node->m_right) == 1) {
            unbalanced_node->m_right =
                _rightRotate(unbalanced_node->m_right);
            unbalanced_node = _leftRotate(unbalanced_node);
            return unbalanced_node;
        }
    }
}

pTreeNode Tree::_rightRotate(pTreeNode x) {
    pTreeNode y = x->m_left;
    pTreeNode t2 = y->m_right;

    y->m_right = x;
    x->m_left = t2;
    
    y->m_parent = x->m_parent;
    x->m_parent = y;

    return y;
}

pTreeNode Tree::_leftRotate(pTreeNode x) {
    pTreeNode y = x->m_right;
    pTreeNode t2 = y->m_left;

    y->m_left = x;
    x->m_right = t2;
    
    y->m_parent = x->m_parent;
    x->m_parent = y;

    return y;
}

int Tree::_height(pTreeNode n) {
    if (n == nullptr) {
        return -1;
    } else {
        int left_subtree_height = _height(n->m_left);
        int right_subtree_height = _height(n->m_right);

        if (left_subtree_height > right_subtree_height) {
            return (left_subtree_height + 1);
        } else {
            return (right_subtree_height + 1);
        }
    }
}

int Tree::_getBalanceFactor(pTreeNode n) {
    if (n == nullptr) {
        return -1;
    }
    return _height(n->m_left) - _height(n->m_right);
}

pTreeNode Tree::remove(int key) {
    pTreeNode ret = nullptr;
    if (m_root == nullptr) {
        return (ret);
    }

    pTreeNode node = _get(m_root, key);
    if (node != nullptr) {
        ret = _remove(node);
        int balance = _getBalanceFactor(ret);
        if(balance != 1 && balance != 0 && balance != -1) {
            //root = _balanceTree(ret, balance);
            _balanceTree(ret, balance);
        }
    }
    return (ret);
}

pTreeNode Tree::_remove(pTreeNode curr) {
    if(_isNodeCleared(curr)) {
        return(nullptr);
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
        return (prev);
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
        return(prev);
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
        return(prev);
    } else {
        /*
        Node to be deleted is an internal node with two children.
        Copy the contents of the inorder successor of the node to be
            deleted and delete the inorder successor.
        The inOrderSuccessor icall works because there is a right tree, 
            so it will find the minimum value in the right tree.
        */
        int currData = curr->getData();
        pTreeNode successor = inOrderSuccessor(curr);
        curr->setData(successor->getData());
        // successor is a minimum
        // so it does not have a left tree
        // so it is an internal node with just one side
        // we already know how to do that so the recursive call is the 
        // most straightforward approach.
        successor->setData(currData);    // simply swapped nodes
        _remove(successor);
        _clearNode(successor);
        // we are done with successor
        // TODO: is this leaking successor
        return (prev);
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

void Tree::deleteTree() {
    std::deque<int> nodeData;
    if(m_root == nullptr) {
        return;
    }
    collectNodeDataPostOrder(m_root, nodeData);
    for(int data : nodeData) {
        pTreeNode node = get(data);
        if(node != nullptr) {
            _clearNode(node);
            node = nullptr;
        }
    }
    m_root = nullptr;
}
