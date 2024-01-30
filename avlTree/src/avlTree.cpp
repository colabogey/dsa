#include "avlTree.h"
#include <iostream>
#include <queue>

int AVLtree::height(Node *r) {
    if (r == NULL) {
        return -1;
    } else {
        int left_subtree_height = height(r->left_child);
        int right_subtree_height = height(r->right_child);

        if (left_subtree_height > right_subtree_height) {
            return (left_subtree_height + 1);
        } else {
            return (right_subtree_height + 1);
        }
    }
}

int AVLtree::getBalanceFactor(Node *n) {
    if (n == NULL) {
        return -1;
    }
    return height(n->left_child) - height(n->right_child);
}

Node* AVLtree::rightRotate(Node *x) {
    Node *y = x->left_child;
    Node *T2 = y->right_child;

    // Perform rotation
    y->right_child = x;
    x->left_child = T2;

    return y;
}

Node* AVLtree::leftRotate(Node *x) {
    Node *y = x->right_child;
    Node *T2 = y->left_child;

    // Perform rotation
    y->left_child = x;
    x->right_child = T2;

    return y;
}

Node* AVLtree::balanceTree(int balance_factor, Node *unbalanced_node) {
    if (balance_factor > 1) {
        // left-left imbalance
        if (getBalanceFactor(unbalanced_node->left_child) >= 0) {
            unbalanced_node = rightRotate(unbalanced_node);
            return unbalanced_node;
        }

        // left-right imbalance
        else if (getBalanceFactor(unbalanced_node->left_child) == -1) {
            unbalanced_node->left_child =
                leftRotate(unbalanced_node->left_child);
            unbalanced_node = rightRotate(unbalanced_node);
            return unbalanced_node;
        }
    }

    if (balance_factor < -1) {
        // right-right imbalance
        if (getBalanceFactor(unbalanced_node->right_child) <= -0) {
            unbalanced_node = leftRotate(unbalanced_node);
            return unbalanced_node;
        }

        // right-left imbalance
        else if (getBalanceFactor(unbalanced_node->right_child) == 1) {
            unbalanced_node->right_child =
                rightRotate(unbalanced_node->right_child);
            unbalanced_node = leftRotate(unbalanced_node);
            return unbalanced_node;
        }
    }
}

Node* AVLtree::insertNode(Node *root, Node *new_node) {
    // inserting the node
    if (root == NULL) {
        root = new_node;
        return root;
    }

    if (new_node->value < root->value) {
        root->left_child = insertNode(root->left_child, new_node);
    } else if (new_node->value > root->value) {
        root->right_child = insertNode(root->right_child, new_node);
    }
    // node has been inserted

    // checking if node needs to be rebalanced
    int bf = getBalanceFactor(root);

    if (bf != -1 && bf != 0 &&
        bf != 1) // if true, then node needs to be rebalanced
    {
        root = balanceTree(bf, root);
    }

    return root; // backtrack
}

Node* AVLtree::deleteNode(Node *root, int val_to_delete) {
    if (root == NULL) {
        return NULL;
    }

    else {
        // node is found and needs to be deleted
        if (val_to_delete == root->value) {
            // scenario 1
            if (root->left_child == NULL && root->right_child == NULL) {
                delete root;
                return NULL;
            }

            // scenario 2
            else if (root->left_child == NULL) {
                Node *temp = root->right_child;
                delete root;
                return temp;
            }

            // scenario 2
            else if (root->right_child == NULL) {
                Node *temp = root->left_child;
                delete root;
                return temp;
            }

            // scenario 3
            else {
                // finding the minimum value in the right subtree
                Node *min_right_subtree;
                Node *current = root->right_child;
                while (current->left_child != NULL) {
                    current = current->left_child;
                }
                min_right_subtree = current;

                // switching the values
                root->value = min_right_subtree->value;

                // Deleting the node with val_to_delete now as a leaf node
                root->right_child =
                    deleteNode(root->right_child, min_right_subtree->value);
            }
        }

        // keep searching for node
        else {
            if (val_to_delete < root->value) {
                root->left_child = deleteNode(root->left_child, val_to_delete);
            }

            else if (val_to_delete > root->value) {
                root->right_child =
                    deleteNode(root->right_child, val_to_delete);
            }
        }

        // checking if node needs to be rebalanced after deletion happens
        int bf = getBalanceFactor(root);

        if (bf != -1 && bf != 0 &&
            bf != 1) // if true, then node needs to be rebalanced
        {
            root = balanceTree(bf, root);
        }

        return root;
    }
}

void AVLtree::levelOrder(Node *root, treeLevels &levels) {
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    std::queue<Node *> q;

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
            Node *node = q.front();
            q.pop();
            nodesInLevel.push_back(node->value);
            // printf("%d ", node->getData());
            if (node->left_child != nullptr) {
                q.push(node->left_child);
            }

            if (node->right_child != nullptr) {
                q.push(node->right_child);
            }

            nodeCount--;
        }
        // printf("\n");
        levels.push_back(nodesInLevel);
    }
}

void AVLtree::prettyPrintTree(Node *r, int space) {
    if (r == NULL) {
        return;
    }
    space += 10;
    prettyPrintTree(r->right_child, space);
    std::cout << std::endl;
    for (int i = 10; i < space; i++) {
        std::cout << " ";
    }
    std::cout << r->value << "\n";
    prettyPrintTree(r->left_child, space);
}

void AVLtree::_preOrder(Node *root) {
    if (root != NULL) {
        std::cout << root->value << " ";
        _preOrder(root->left_child);
        _preOrder(root->right_child);
    }
}
