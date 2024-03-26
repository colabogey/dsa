/*
Number of Visible Nodes
There is a binary tree with N nodes. You are viewing the tree from its left side
and can see only the leftmost nodes at each level. Return the number of visible
nodes. Note: You can see only the leftmost nodes, but that doesn't mean they
have to be left nodes. The leftmost node at a level could be a right node.
Signature
int visibleNodes(Node root) {
Input
The root node of a tree, where the number of nodes is between 1 and 1000, and
the value of each node is between 0 and 1,000,000,000 Output An int representing
the number of visible nodes. Example

            8  <------ root
           / \
         3    10
        / \     \
       1   6     14
          / \    /
         4   7  13

output = 4

*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

struct Node2 {
    int data;
    Node2 *left;
    Node2 *right;
    Node2() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node2(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Add any helper functions you may need here

int levelOrder(Node2 *root) {
    queue<Node2 *> nq;
    int levels = 0;
    nq.push(root);
    while (!nq.empty()) {
        int nodeCount = nq.size();
        while (nodeCount > 0) {
            Node2 *n = nq.front();
            nq.pop();
            nodeCount--;
            if (n->left) {
                nq.push(n->left);
            }
            if (n->right) {
                nq.push(n->right);
            }
        }
        levels++;
    }
    return levels;
}

int getDepth(Node2 *root) {
    if (root == NULL) {
        return 0;
    }
    int lVal = getDepth(root->left);
    int rVal = getDepth(root->right);
    if (lVal > rVal) {
        return lVal + 1;
    } else {
        return rVal + 1;
    }
}

int visibleNodes(Node2 *root) {
    // Write your code here
    // return levelOrder(root);
    return getDepth(root);
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
static void printInteger(int n) { cout << "[" << n << "]"; }

static int test_case_number = 1;
static int failed = 0;

static void check(int expected, int output) {
    bool result = (expected == output);
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    } else {
        failed++;
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(output);
        cout << endl;
    }
    test_case_number++;
}

int main_tree_num_visible_nodes() {

    Node2 *root_1 = new Node2(8);
    root_1->left = new Node2(3);
    root_1->right = new Node2(10);
    root_1->left->left = new Node2(1);
    root_1->left->right = new Node2(6);
    root_1->right->right = new Node2(14);
    root_1->left->right->left = new Node2(4);
    root_1->left->right->right = new Node2(7);
    root_1->right->right->left = new Node2(13);
    int expected_1 = 4;
    int output_1 = visibleNodes(root_1);
    check(expected_1, output_1);

    Node2 *root_2 = new Node2(10);
    root_2->left = new Node2(8);
    root_2->right = new Node2(15);
    root_2->left->left = new Node2(4);
    root_2->left->left->right = new Node2(5);
    root_2->left->left->right->right = new Node2(6);
    root_2->right->left = new Node2(14);
    root_2->right->right = new Node2(16);
    int expected_2 = 5;
    int output_2 = visibleNodes(root_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
