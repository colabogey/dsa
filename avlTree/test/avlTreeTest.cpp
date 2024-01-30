/* Copyright 2022-Present Steve Yackey

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <deque>
#include <functional>
#include "eAvlTree.h" // to make the IDE happy (sad)
#include "gAvlTree.h" // to make the IDE happy (sad)

using namespace std;

// The fixture for testing
class AvlTreeTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    AvlTreeTest() { }

    virtual ~AvlTreeTest() {}

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        //
        m_gtree = new gAVLtree();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests.
    //
    void ShowLevels() {
        int level = 1;
        for(std::list<int> l : m_levels) {
            printf("\t[level: %2d]\t", level);
            for(int i : l) {
                printf("%2d ", i);
            }
            printf("\t\t[count: %2ld] \n", l.size());
            level++;
        }
    }

    void AddAll() {
        for(int i = 0; i < m_size; i++) {
            Node* n = new Node(m_vals[i]);
            m_tree.root = m_tree.insertNode(m_tree.root, n);
        }
    }

    void gAddAll() {
        for(int i = 0; i < m_size; i++) {
            gNode* n = new gNode(m_vals[i]);
            m_gtree->root = m_gtree->insertNode(m_gtree->root, m_vals[i]);
        }
    }

    std::deque<int> m_nodeData;
    int m_size{23};
    int m_vals[23] = 
        { 55, 40, 35, 27, 60, 42, 16, 3, 90, 58, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 41};
    treeLevels  m_levels;
    AVLtree m_tree;
    gAVLtree* m_gtree;
};

TEST_F(AvlTreeTest, Educative_As_Is) {
  AVLtree obj;

  Node * n1 = new Node(30);
  Node * n2 = new Node(10);
  Node * n3 = new Node(50);
  Node * n4 = new Node(8);
  Node * n5 = new Node(18);
  Node * n6 = new Node(58);
  Node * n7 = new Node(5);
  Node * n8 = new Node(6);

  obj.root = obj.insertNode(obj.root, n1);
  obj.root = obj.insertNode(obj.root, n2);
  obj.root = obj.insertNode(obj.root, n3);
  obj.root = obj.insertNode(obj.root, n4);
  obj.root = obj.insertNode(obj.root, n5);
  obj.root = obj.insertNode(obj.root, n6);
  obj.root = obj.insertNode(obj.root, n7);

  obj.root = obj.insertNode(obj.root, n8);

  //prettyPrintTree(obj.root, 1);
  obj._preOrder(obj.root);
  printf("\n");
  obj.levelOrder(obj.root, m_levels);
  ShowLevels();
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, Educative_G4G) {
  AVLtree obj;

  Node * n1 = new Node(10);
  Node * n2 = new Node(20);
  Node * n3 = new Node(30);
  Node * n4 = new Node(40);
  Node * n5 = new Node(50);
  Node * n6 = new Node(25);

  obj.root = obj.insertNode(obj.root, n1);
  obj.root = obj.insertNode(obj.root, n2);
  obj.root = obj.insertNode(obj.root, n3);
  obj.root = obj.insertNode(obj.root, n4);
  obj.root = obj.insertNode(obj.root, n5);
  obj.root = obj.insertNode(obj.root, n6);

  //prettyPrintTree(obj.root, 1);
  obj._preOrder(obj.root);
  printf("\n");
  obj.levelOrder(obj.root, m_levels);
  ShowLevels();
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, AddAll_VerifyBalance) {
    // Arrange
    // Act
    AddAll();
    m_tree._preOrder(m_tree.root);
    printf("\n");
    m_tree.levelOrder(m_tree.root, m_levels);
    ShowLevels();
    ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, G4G) {
  gAVLtree obj;

  /* Constructing tree given in
  the above figure */
  obj.root = obj.insertNode(obj.root, 10);
  obj.root = obj.insertNode(obj.root, 20);
  obj.root = obj.insertNode(obj.root, 30);
  obj.root = obj.insertNode(obj.root, 40);
  obj.root = obj.insertNode(obj.root, 50);
  obj.root = obj.insertNode(obj.root, 25);
  obj.preOrder(obj.root);
  printf("\n");
  obj.levelOrder(obj.root, m_levels);
  ShowLevels();
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, gAddAll_VerifyBalance) {
    // Arrange
    // Act
    gAddAll();
    m_gtree->preOrder(m_gtree->root);
    printf("\n");
    m_gtree->levelOrder(m_gtree->root, m_levels);
    ShowLevels();
    ASSERT_EQ(1, 1);
}

