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
#include "eAvlTree.h"
#include "gAvlTree.h"
#include "tree.h"

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

    void ShowNodeData(std::string s) {
        printf("\t%10s: ", s.c_str());
        for(int i : m_nodeData) {
            printf("%2d ", i);
        }
        printf("\n");
    }

    void ClearNodeData() {
        m_nodeData.clear();
    }

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

    void ClearLevels() {
        for(std::list<int> l : m_levels) {
            l.clear();
        }
        m_levels.clear();
    }


    void AddAll() {
        for(int i = 0; i < m_size; i++) {
            Node* n = new Node(m_vals[i]);
            m_avltree.root = m_avltree.insertNode(m_avltree.root, n);
        }
    }

    void tAddAll() {
        for(int i = 0; i < m_size; i++) {
            //Node* n = new Node(m_vals[i]);
            m_tree.m_root = m_tree.add(m_tree.m_root, nullptr, m_vals[i]);
        }
    }

    void gAddAll() {
        for(int i = 0; i < m_size; i++) {
            gNode* n = new gNode(m_vals[i]);
            m_gtree->root = m_gtree->insertNode(m_gtree->root, m_vals[i]);
        }
    }

    int m_size{23};
    int m_vals[23] = 
        { 55, 40, 35, 27, 60, 42, 16, 3, 90, 58, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 41};
    treeLevels  m_levels;
    std::deque<int> m_nodeData;
    Tree m_tree;
    AVLtree m_avltree;
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
    m_avltree._preOrder(m_avltree.root);
    printf("\n");
    m_avltree.levelOrder(m_avltree.root, m_levels);
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

TEST_F(AvlTreeTest, Add_RotateRight) {
  //arrange
  Tree obj;
  //act
  obj.m_root = obj.add(obj.m_root, nullptr, 30);
  obj.m_root = obj.add(obj.m_root, nullptr, 20);
  obj.m_root = obj.add(obj.m_root, nullptr, 10);
  //
  obj.collectNodeDataPreOrder(obj.m_root, m_nodeData);
  ShowNodeData("PreOrder");
  //
  obj.levelOrder(obj.m_root, m_levels);
  ShowLevels();
  //Assert
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, Add_RotateLeft) {
  //arrange
  Tree obj;
  //act
  obj.m_root = obj.add(obj.m_root, nullptr, 10);
  obj.m_root = obj.add(obj.m_root, nullptr, 20);
  obj.m_root = obj.add(obj.m_root, nullptr, 30);
  //
  obj.collectNodeDataPreOrder(obj.m_root, m_nodeData);
  ShowNodeData("PreOrder");
  //
  obj.levelOrder(obj.m_root, m_levels);
  ShowLevels();
  //Assert
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, Add_RotateLeftRight) {
  //arrange
  Tree obj;
  //act
  obj.m_root = obj.add(obj.m_root, nullptr, 30);
  obj.m_root = obj.add(obj.m_root, nullptr, 10);
  obj.m_root = obj.add(obj.m_root, nullptr, 20);
  //
  obj.collectNodeDataPreOrder(obj.m_root, m_nodeData);
  ShowNodeData("PreOrder");
  //
  obj.levelOrder(obj.m_root, m_levels);
  ShowLevels();
  //Assert
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, Add_RotateRightLeft) {
  //arrange
  Tree obj;
  //act
  obj.m_root = obj.add(obj.m_root, nullptr, 10);
  obj.m_root = obj.add(obj.m_root, nullptr, 30);
  obj.m_root = obj.add(obj.m_root, nullptr, 20);
  //
  obj.collectNodeDataPreOrder(obj.m_root, m_nodeData);
  ShowNodeData("PreOrder");
  //
  obj.levelOrder(obj.m_root, m_levels);
  ShowLevels();
  //Assert
  ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, tAddAll_VerifyBalance) {
    // Arrange
    // Act
    tAddAll();
    m_tree.collectNodeDataPreOrder(m_tree.m_root, m_nodeData);
    ShowNodeData("PreOrder");
    //
    m_tree.levelOrder(m_tree.m_root, m_levels);
    ShowLevels();
    // Assert
    ASSERT_EQ(1, 1);
}

TEST_F(AvlTreeTest, tAddAll_Remove45) {
    // Arrange
    // Act
    tAddAll();
    m_tree.collectNodeDataPreOrder(m_tree.m_root, m_nodeData);
    ShowNodeData("PreOrder");
    ClearNodeData();
    //
    m_tree.levelOrder(m_tree.m_root, m_levels);
    ShowLevels();
    ClearLevels();
    m_tree.remove(45);
    //
    printf("\n");
    m_tree.collectNodeDataPreOrder(m_tree.m_root, m_nodeData);
    ShowNodeData("PreOrder");
    ClearNodeData();
    //
    m_tree.levelOrder(m_tree.m_root, m_levels);
    ShowLevels();
    // Assert
    ASSERT_EQ(1, 1);
}

