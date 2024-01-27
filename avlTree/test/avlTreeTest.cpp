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
#include "avlTree.h" // to make the IDE happy (sad)

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
        m_pAvlTree = make_shared<AvlTree>();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        pAvlTreeNode root = m_pAvlTree->getRoot();
        m_pAvlTree->deleteTree();
        m_pAvlTree = nullptr;

        m_nodeData.clear();
    }

    // Objects declared here can be used by all tests.
    //

    int AddAll() {
        for(int i = 0; i < m_size; i++)
        {
            m_pAvlTree->add(m_vals[i]);
        }
        return(m_size);
    }

     int AddSecondary() {
        for(int i = 0; i < m_sizeSecondary; i++)
        {
            m_pAvlTree->add(m_valsSecondary[i]);
        }
        return(m_sizeSecondary);
    }

    int AddAllAndSecondary() {
        int a = AddAll();
        int b = AddSecondary();
        return(a + b);
    }

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

    std::shared_ptr<AvlTree> m_pAvlTree;
    treeLevels  m_levels;
    std::deque<int> m_nodeData;
    int m_size{10};
    int m_vals[10] = {55, 40, 35, 27, 60, 42, 16, 3, 90, 58};

    int m_sizeSecondary{13};
    int m_valsSecondary[13] = {54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 41};
};

TEST_F(AvlTreeTest, AddOne_Verify_ByNodeCount) {
    // arrange
    int toAdd = 1;
    int spot = 0;
    m_pAvlTree->add(m_vals[0]);
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(m_nodeData.size(), toAdd);
}

TEST_F(AvlTreeTest, AddTwo_Verify_ByNodeCount) {
    // arrange
    int toAdd = 2;
    int spot = 0;
    m_pAvlTree->add(m_vals[0]);
    m_pAvlTree->add(m_vals[1]);
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(m_nodeData.size(), toAdd);
}

TEST_F(AvlTreeTest, AddAll_GetValue_Verify_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = m_vals[5];
    AddAll();
    // act
    pAvlTreeNode node = m_pAvlTree->get(keyToGet);
    if(node != nullptr) {
        rVal = node->getData();
    }
    // assert
    ASSERT_EQ(rVal, m_vals[5]);
}

TEST_F(AvlTreeTest, AddAll_GetBogusValue_Verify_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = 697;
    int toAdd = AddAll();
    // act
    pAvlTreeNode node = m_pAvlTree->get(keyToGet);
    if(node != nullptr) {
        rVal = node->getData();
    }
    // assert
    ASSERT_EQ(rVal, -1);
}

TEST_F(AvlTreeTest, AddAll_Verify_Depth) {
    // arrange
    int toAdd = AddAll();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    int depth = m_pAvlTree->getDepth();
    // assert
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ASSERT_EQ(depth, 6);
}

TEST_F(AvlTreeTest, AddAllAndSecondary_RemoveNodeWithLeftOnly_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 27;
    int toAdd = AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("InOrder");
    ClearNodeData();
    // act
    pAvlTreeNode removed = m_pAvlTree->remove(valToRemove);
    printf("\tRemoved (%d)\n", removed->getData());
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(countBefore, (countAfter + 1));
}

TEST_F(AvlTreeTest, AddAllAndSecondary_RemoveNodeWithRightOnly_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 60;
    int toAdd = AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("Inorder:");
    ClearNodeData();
    // act
    pAvlTreeNode removed = m_pAvlTree->remove(valToRemove);
    printf("\tRemoved (%d)\n", removed->getData());
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(countBefore, (countAfter + 1));
}

TEST_F(AvlTreeTest, AddAllAndSecondary_RemoveLeaf_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 3;
    int toAdd = AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("Inorder:");
    ClearNodeData();
    // act
    pAvlTreeNode removed = m_pAvlTree->remove(valToRemove);
    printf("\tRemoved (%d)\n", removed->getData());
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(countBefore, (countAfter + 1));
}

TEST_F(AvlTreeTest, AddAllAndSecondary_RemoveNodeWithLeftAndRight_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 40;
    int toAdd = AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("Inorder:");
    ClearNodeData();
    // act
    pAvlTreeNode removed = m_pAvlTree->remove(valToRemove);
    printf("\tRemoved (%d)\n", removed->getData());
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    m_pAvlTree->levelOrder(root, m_levels);
    ShowLevels();
    // assert
    ASSERT_EQ(countBefore, (countAfter + 1));
}

TEST_F(AvlTreeTest, AddAllAndSecondary_RemoveRoot_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 55;
    AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("InOrder");
    ClearNodeData();
    // act
    pAvlTreeNode removed = m_pAvlTree->remove(valToRemove);
    printf("\tRemoved (%d)\n", removed->getData());
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(countBefore, (countAfter + 1));
    ASSERT_EQ(removed->getData(), valToRemove);
}

TEST_F(AvlTreeTest, InOrderSuccessor_42) {
    // arrange
    int valToGet = 42;
    int valExpected = 43;
    int valFromNode = -1;
    int toAdd = AddAllAndSecondary();
    // act
    pAvlTreeNode node = m_pAvlTree->get(valToGet);
    pAvlTreeNode successor = m_pAvlTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(AvlTreeTest, InOrderSuccessor_40) {
    // arrange
    int valToGet = 40;
    int valExpected = 41;
    int valFromNode = -1;
    int toAdd = AddAllAndSecondary();
    // act
    pAvlTreeNode node = m_pAvlTree->get(valToGet);
    pAvlTreeNode successor = m_pAvlTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(AvlTreeTest, InOrderSuccessor_35) {
    // arrange
    int valToGet = 35;
    int valExpected = 40;
    int valFromNode = -1;
    int toAdd = AddAllAndSecondary();
    // act
    pAvlTreeNode node = m_pAvlTree->get(valToGet);
    pAvlTreeNode successor = m_pAvlTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(AvlTreeTest, InOrderSuccessor_FromExample_1) {
    // arrange
    int ary[] = { 20, 8, 22, 4, 12, 10, 14 };
    int valToGet = 14;
    int valExpected = 20;
    int valFromNode = -1;
    for(int i = 0; i < (sizeof(ary) / sizeof(int)) ; i++)
    {
        m_pAvlTree->add(ary[i]);
    }
    // act
    pAvlTreeNode node = m_pAvlTree->get(valToGet);
    pAvlTreeNode successor = m_pAvlTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(AvlTreeTest, LevelOrder) {
    // arrange
    int valExpected = 1;
    AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    m_pAvlTree->levelOrder(root, m_levels);
    ShowLevels();
    // assert
    ASSERT_EQ(valExpected, 1);
}

TEST_F(AvlTreeTest, AddAllAndSecondary_Rebalance_VerifyWithNodeCount) {
    // arrange
    AddAllAndSecondary();
    pAvlTreeNode origRoot = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(origRoot, m_nodeData);
    int countBefore = m_nodeData.size();
    ShowNodeData("InOrder");
    ClearNodeData();
    m_pAvlTree->levelOrder(origRoot, m_levels);
    ShowLevels();
    ClearLevels();
    // act
    m_pAvlTree->rebalance();
    pAvlTreeNode newRoot = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(newRoot, m_nodeData);
    int countAfter = m_nodeData.size();
    ShowNodeData("InOrder");
    m_pAvlTree->levelOrder(newRoot, m_levels);
    ShowLevels();
    // assert
    ASSERT_EQ(countAfter, countBefore);
}

TEST_F(AvlTreeTest, InPrePostOrder) {
    // arrange
    int valExpected = 1;
    AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ClearNodeData();

    m_pAvlTree->collectNodeDataPreOrder(root, m_nodeData);
    ShowNodeData("PreOrder");
    ClearNodeData();

    m_pAvlTree->collectNodeDataPostOrder(root, m_nodeData);
    ShowNodeData("PostOrder");
    // assert
    ASSERT_EQ(valExpected, 1);
}

TEST_F(AvlTreeTest, DeleteTree_VerifyWithNodeCount) {
    // arrange
    AddAllAndSecondary();
    pAvlTreeNode root = m_pAvlTree->getRoot();
    // act
    m_pAvlTree->deleteTree();
    root = m_pAvlTree->getRoot();
    m_pAvlTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(0, m_nodeData.size());
}

