
#include "avlTree.h"
#include <iostream>
#include <algorithm>

void AvlTree::add(int data) {
    pAvlTreeNode newItem = std::make_shared<AvlTreeNode>();
    newItem->setData(data);
    if (m_root == nullptr) {
        m_root = newItem;
    } else {
        _add(m_root, newItem);
    }
}

void AvlTree::_add(pAvlTreeNode root, pAvlTreeNode newNode) {
    if (root == nullptr) {
        return;
    }

    if (newNode->getData() < root->getData()) {
        if (root->getLeft() == nullptr) {
            root->setLeft(newNode);
            newNode->setParent(root);
            return;
        } else {
            _add(root->getLeft(), newNode);
        }
    } else if (newNode->getData() > root->getData()) {
        if (root->getRight() == nullptr) {
            root->setRight(newNode);
            newNode->setParent(root);
            return;
        } else {
            _add(root->getRight(), newNode);
        }
    }
    // else its equal which is not allowed so don't do anything
}
pAvlTreeNode AvlTree::remove(int key) {
    pAvlTreeNode ret = nullptr;
    if (m_root == nullptr) {
        return (ret);
    }

    pAvlTreeNode node = _get(m_root, key);
    if (node != nullptr) {
        ret = _remove(node);
    }
    return (ret);
}

pAvlTreeNode AvlTree::_remove(pAvlTreeNode curr) {
    if (_isNodeCleared(curr)) {
        return (curr);
    }

    pAvlTreeNode prev = curr->getParent();

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
        if (prev->getLeft() == curr) {
            prev->setLeft(curr->getRight());
        } else {
            prev->setRight(curr->getRight());
        }
        _clearNode(curr);
        return (curr);
    } else if (curr->getRight() == nullptr) {
        // internal node with just one 'side'
        // left side only
        // delete the node and move its child up to take its place
        if (prev->getLeft() == curr) {
            prev->setLeft(curr->getLeft());
        } else {
            prev->setRight(curr->getLeft());
        }
        _clearNode(curr);
        return (curr);
    } else {
        /*
        Node to be deleted is an internal node with two children.
        Copy the contents of the inorder successor of the node to be
        deleted and delete the inorder successor.
        The onOrderSuccessor call works because there is a right tree,
        so it will find the minimum value in the right tree.
        */
        int currData = curr->getData();
        pAvlTreeNode successor = inOrderSuccessor(curr);
        curr->setData(successor->getData());
        // successor is a minimum
        // so it does not have a left tree
        // so it is an internal node with just one side
        // we already know how to do that so the recursive call is
        // the most straightforward approach.
        successor->setData(currData); // simply swapped nodes
        _remove(successor);
        _clearNode(successor);
        // we are done with successor
        // TODO: is this leaking successor
        return (successor);
    }
}

void AvlTree::_clearNode(pAvlTreeNode node) {
    node->setLeft(nullptr);
    node->setRight(nullptr);
    node->setParent(nullptr);
}

bool AvlTree::_isNodeCleared(pAvlTreeNode node) {
    bool bRet = false;
    if (node->getLeft() == nullptr && node->getRight() == nullptr &&
        node->getParent() == nullptr) {
        bRet = true;
    }
    return bRet;
}

pAvlTreeNode AvlTree::get(int key) {
    pAvlTreeNode node = nullptr;
    if (m_root != nullptr) {
        node = _get(m_root, key);
    }
    return (node);
}

pAvlTreeNode AvlTree::_get(pAvlTreeNode root, int key) {
    if (root == nullptr) {
        return (nullptr);
    }

    if (root->getData() == key) {
        return (root);
    }

    if (key < root->getData()) {
        return (_get(root->getLeft(), key));
    } else {
        return (_get(root->getRight(), key));
    }
}

void AvlTree::collectNodeDataInOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        _collectNodeDataInOrder(root, q);
    }
}

void AvlTree::_collectNodeDataInOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        _collectNodeDataInOrder(root->getLeft(), q);
        q.push_back(root->getData());
        _collectNodeDataInOrder(root->getRight(), q);
    }
}

void AvlTree::collectNodeDataPostOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        _collectNodeDataPostOrder(root, q);
    }
}

void AvlTree::_collectNodeDataPostOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        _collectNodeDataPostOrder(root->getLeft(), q);
        _collectNodeDataPostOrder(root->getRight(), q);
        q.push_back(root->getData());
    }
}

void AvlTree::collectNodeDataPreOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        _collectNodeDataPreOrder(root, q);
    }
}

void AvlTree::_collectNodeDataPreOrder(pAvlTreeNode root, std::deque<int> &q) {
    if (root != nullptr) {
        q.push_back(root->getData());
        _collectNodeDataPreOrder(root->getLeft(), q);
        _collectNodeDataPreOrder(root->getRight(), q);
    }
}

void AvlTree::collectNodesInOrder(pAvlTreeNode root) {
    if (root != nullptr) {
        _collectNodesInOrder(root);
    }
}

void AvlTree::_collectNodesInOrder(pAvlTreeNode root) {
    if (root != nullptr) {
        _collectNodesInOrder(root->getLeft());
        m_nodes.push_back(root);
        _collectNodesInOrder(root->getRight());
    }
}

void AvlTree::rebalance() {
    _collectNodesInOrder(m_root);
    pAvlTreeNode newRoot = _rebalance(m_root, 0, (m_nodes.size() - 1));
    m_root = newRoot;
    m_nodes.clear();
}

pAvlTreeNode AvlTree::_rebalance(pAvlTreeNode root, int indexLeft, int indexRight) {
    if (indexLeft > indexRight) {
        return nullptr;
    }

    int medianIndex = (indexLeft + indexRight) / 2;
    // printf("m (%d), l (%d), r(%d)\n",
    // m_nodes[medianIndex]->getData(),
    // m_nodes[indexLeft]->getData(),
    // m_nodes[indexRight]->getData());
    pAvlTreeNode spNode = m_nodes[medianIndex];
    spNode->setParent(root);
    spNode->setLeft(_rebalance(spNode, indexLeft, medianIndex - 1));
    spNode->setRight(_rebalance(spNode, medianIndex + 1, indexRight));
    return (spNode);
}

int AvlTree::getDepth() {
    int i = _getDepth(m_root);
    return (i);
}

int AvlTree::_getDepth(pAvlTreeNode root) {
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

pAvlTreeNode AvlTree::inOrderSuccessor(pAvlTreeNode node) {

    if (node == nullptr) {
        return (node);
    }

    pAvlTreeNode successor = node;
    pAvlTreeNode nextLeft = nullptr;
    pAvlTreeNode nextRight = nullptr;
    if ((nextRight = node->getRight()) != nullptr) {
        successor = _getLeastValuePresent(nextRight);
    } else {
        successor = _getNodeThatIsLeftChildOfParent(node);
    }
    return (successor);
}

pAvlTreeNode AvlTree::_getNodeThatIsLeftChildOfParent(pAvlTreeNode node) {
    pAvlTreeNode parent = node->getParent();
    while ((parent != nullptr) && (node == parent->getRight())) {
        node = parent;
        parent = parent->getParent();
    }
    return (parent);
}

pAvlTreeNode AvlTree::_getLeastValuePresent(pAvlTreeNode node) {
    pAvlTreeNode curr = node;
    while (curr->getLeft() != nullptr) {
        curr = curr->getLeft();
    }
    return (curr);
}

void AvlTree::levelOrder(pAvlTreeNode root, treeLevels &levels) {
    // Base Case
    if (root == nullptr)
        return;

    // Create an empty queue for level order traversal
    std::queue<pAvlTreeNode> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
        // printf("nodeCount (%d)\n", nodeCount);
        std::list<int> nodesInLevel;

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0) {
            pAvlTreeNode node = q.front();
            q.pop();
            nodesInLevel.push_back(node->getData());
            // printf("%d ", node->getData());
            if (node->getLeft() != nullptr) {
                q.push(node->getLeft());
            }

            if (node->getRight() != nullptr) {
                q.push(node->getRight());
            }

            nodeCount--;
        }
        // printf("\n");
        levels.push_back(nodesInLevel);
    }
}

void AvlTree::deleteTree() {
    std::deque<int> nodeData;
    if (m_root == nullptr) {
        return;
    }
    collectNodeDataPostOrder(m_root, nodeData);
    for (int data : nodeData) {
        pAvlTreeNode node = get(data);
        if (node != nullptr) {
            _clearNode(node);
            node = nullptr;
        }
    }
    m_root = nullptr;
}

int AvlTree::_height(pAvlTreeNode n) {
    if(n == nullptr) {
        return 0;
    }
    return(n->getHeight());
}


// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
pAvlTreeNode AvlTree::_rightRotate(pAvlTreeNode y) {
    pAvlTreeNode x = y->getLeft();
    pAvlTreeNode T2 = x->getRight();

    // Perform rotation
    x->getRight() = y;
    y->getLeft() = T2;

    // Update heights
    y->setHeight(
        std::max(_height(y->getLeft()), _height(y->getRight())) + 1);
    x->setHeight(
        std::max(_height(x->getLeft()), _height(x->getRight())) + 1);

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
pAvlTreeNode AvlTree::_leftRotate(pAvlTreeNode x) {
    pAvlTreeNode y = x->getRight();
    pAvlTreeNode T2 = y->getLeft();

    // Perform rotation
    y->getLeft() = x;
    x->getRight() = T2;

    // Update heights
    x->setHeight(
        std::max(_height(x->getLeft()), _height(x->getRight())) + 1);
    y->setHeight(
        std::max(_height(y->getLeft()), _height(y->getRight())) + 1);

    // Return new root
    return y;
}

// Get Balance factor of node N
int AvlTree::_getBalance(pAvlTreeNode N) {
    if (N == nullptr)
        return 0;
    return _height(N->getLeft()) - _height(N->getRight());
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
pAvlTreeNode AvlTree::_rotate(pAvlTreeNode node) {
    /* 1. Perform the normal BST insertion */
    // if (node == NULL)
    // return (newNode(key));

    // if (key < node->key)
    // node->left = insert(node->left, key);
    // else if (key > node->key)
    // node->right = insert(node->right, key);
    // else // Equal keys are not allowed in BST
    // return node;

    /* 2. Update height of this ancestor node */
    node->setHeight( 1 + std::max(_height(node->getLeft()),
                                  _height(node->getRight())));

    /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
    int balance = _getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && node->getData() < node->getLeft()->getData())
        return _rightRotate(node);

    // Right Right Case
    if (balance < -1 && node->getData() > node->getRight()->getData())
        return _leftRotate(node);

    // Left Right Case
    if (balance > 1 && node->getData() > node->getLeft()->getData()) {
        node->getLeft() = _leftRotate(node->getLeft());
        return _rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && node->getData() < node->getRight()->getData()) {
        node->getRight() = _rightRotate(node->getRight());
        return _leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void AvlTree::_preOrder(pAvlTreeNode root) {
    if (root != nullptr) {
        std::cout << root->getData() << " ";
        _preOrder(root->getLeft());
        _preOrder(root->getRight());
    }
}

#ifdef NOT_HIDDEN
// Driver Code
int main() {
    Node *root = nullptr;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
                            30
                    / \
                    20 40
                    / \ \
            10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
#endif
