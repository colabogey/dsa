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
#include <tree.h>

using namespace std;

// The fixture for testing
class TreeTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    TreeTest() { }

    virtual ~TreeTest() {}

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        //
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        m_nodeData.clear();
    }

    // Objects declared here can be used by all tests.
    //

    void AddAll(std::shared_ptr<Tree> pTree) {
        for(int i = 0; i < m_size; i++)
        {
            pTree->add(m_vals[i]);
        }
    }

    void AddSecondary(std::shared_ptr<Tree> pTree) {
        for(int i = m_sizeSecondary, spot = 0; i > 0; i--)
        {
            pTree->add(m_valsSecondary[spot]);
            spot++;
        }
    }

    void AddAllAndSecondary(std::shared_ptr<Tree> pTree) {
        AddAll(pTree);
        AddSecondary(pTree);
    }

    void ShowNodeData(std::string s) {
        printf("\t%s: ", s.c_str());
        for(int i : m_nodeData) {
            printf("%d ", i);
        }
        printf("\n");
    }

    void ClearNodeData() {
        m_nodeData.clear();
    }

    std::deque<int> m_nodeData;

    int m_size{9};
    int m_vals[9] = {55, 40, 35, 27, 60, 42, 16, 3, 90 };

    int m_sizeSecondary{13};
    int m_valsSecondary[13] = {54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 41};
};

TEST_F(TreeTest, AddOne_Verify_ByNodeCount) {
    // arrange
    int toAdd = 1;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    pTree->add(m_vals[0]);
    pTreeNode root = pTree->getRoot();
    // act
    int count = pTree->getNodeCount();
    // assert
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, AddTwo_Verify_ByNodeCount) {
    // arrange
    int toAdd = 2;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    pTree->add(m_vals[0]);
    pTree->add(m_vals[1]);
    pTreeNode root = pTree->getRoot();
    // act
    int count = pTree->getNodeCount();
    // assert
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, AddAll_GetValue_Verify_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = m_vals[5];
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAll(pTree);
    int count = pTree->getNodeCount();
    // act
    pTreeNode node = pTree->get(keyToGet);
    if(node != nullptr) {
        rVal = node->getData();
    }
    // assert
    ASSERT_EQ(rVal, m_vals[5]);
}

TEST_F(TreeTest, AddAllRecursive_Verify_ByNodeCount) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    for(int i = toAdd; i > 0; i--)
    {
        pTree->addRecursive(m_vals[spot]);
        spot++;
    }
    pTreeNode root = pTree->getRoot();
    // act
    int count = pTree->getNodeCount();
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, AddAll_GetBogusValue_Verify_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = 697;
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAll(pTree);
    int count = pTree->getNodeCount();
    // act
    pTreeNode node = pTree->get(keyToGet);
    if(node != nullptr) {
        rVal = node->getData();
    }
    // assert
    ASSERT_EQ(rVal, -1);
}

TEST_F(TreeTest, AddAll_Verify_Depth) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAll(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    int depth = pTree->getDepth();
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ASSERT_EQ(depth, 6);
}

TEST_F(TreeTest, AddAllAndSecondaryRecursive_Verify_Depth) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    for(int i = toAdd; i > 0; i--)
    {
        pTree->addRecursive(m_vals[spot]);
        spot++;
    }

    for(int i = m_sizeSecondary, spot = 0; i > 0; i--)
    {
        pTree->addRecursive(m_valsSecondary[spot]);
        spot++;
    }
    pTreeNode root = pTree->getRoot();
    // act
    int depth = pTree->getDepth();
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ASSERT_EQ(depth, 15);
}

TEST_F(TreeTest, AddAllAndSecondaryRecursive_Verify_ByNodeCount) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    for(int i = toAdd; i > 0; i--)
    {
        pTree->addRecursive(m_vals[spot]);
        spot++;
    }

    for(int i = m_sizeSecondary, spot = 0; i > 0; i--)
    {
        pTree->addRecursive(m_valsSecondary[spot]);
        spot++;
    }
    pTreeNode root = pTree->getRoot();
    // act
    int count = pTree->getNodeCount();
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    // assert
    ASSERT_EQ(count, m_size + m_sizeSecondary);
}

TEST_F(TreeTest, AddAllAndSecondary_RemoveNodeWithLeftOnly_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 27;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTreeNode removed = pTree->remove(valToRemove);
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    int count = pTree->getNodeCount();
    ASSERT_EQ(count, ((m_size + m_sizeSecondary) - 1));
}

TEST_F(TreeTest, AddAllAndSecondary_RemoveNodeWithRightOnly_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 60;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTreeNode removed = pTree->remove(valToRemove);
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    int count = pTree->getNodeCount();
    ASSERT_EQ(count, ((m_size + m_sizeSecondary) - 1));
}

TEST_F(TreeTest, AddAllAndSecondary_RemoveLeaf_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 3;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTreeNode removed = pTree->remove(valToRemove);
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    int count = pTree->getNodeCount();
    ASSERT_EQ(count, ((m_size + m_sizeSecondary) - 1));
}

TEST_F(TreeTest, AddAllAndSecondary_RemoveNodeWithLeftAndRight_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 40;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTreeNode removed = pTree->remove(valToRemove);
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    int count = pTree->getNodeCount();
    ASSERT_EQ(count, ((m_size + m_sizeSecondary) - 1));
}

TEST_F(TreeTest, AddAllAndSecondary_RemoveRoot_Verify_ByNodeCount) {
    // arrange
    int valToRemove = 55;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    ClearNodeData();
    pTreeNode removed = pTree->remove(valToRemove);
    // assert
    pTree->collectNodeDataInOrder(root, m_nodeData);
    ShowNodeData("InOrder");
    int count = pTree->getNodeCount();
    ASSERT_EQ(count, ((m_size + m_sizeSecondary) - 1));
}

TEST_F(TreeTest, InOrderSuccessor_42) {
    // arrange
    int valToGet = 42;
    int valExpected = 43;
    int valFromNode = -1;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    // act
    pTreeNode node = pTree->get(valToGet);
    pTreeNode successor = pTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(TreeTest, InOrderSuccessor_40) {
    // arrange
    int valToGet = 40;
    int valExpected = 41;
    int valFromNode = -1;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    // act
    pTreeNode node = pTree->get(valToGet);
    pTreeNode successor = pTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(TreeTest, InOrderSuccessor_35) {
    // arrange
    int valToGet = 35;
    int valExpected = 40;
    int valFromNode = -1;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    // act
    pTreeNode node = pTree->get(valToGet);
    pTreeNode successor = pTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(TreeTest, InOrderSuccessor_FromExample_1) {
    // arrange
    int ary[] = { 20, 8, 22, 4, 12, 10, 14 };
    int valToGet = 14;
    int valExpected = 20;
    int valFromNode = -1;
    auto pTree = make_shared<Tree>();
    for(int i = 0; i < (sizeof(ary) / sizeof(int)) ; i++)
    {
        pTree->add(ary[i]);
    }
    // act
    pTreeNode node = pTree->get(valToGet);
    pTreeNode successor = pTree->inOrderSuccessor(node);
    if(node != nullptr) {
        valFromNode = successor->getData();
    }
    // assert
    ASSERT_EQ(valExpected, valFromNode);
}

TEST_F(TreeTest, LevelOrder) {
    // arrange
    int valExpected = 1;
    int spot = 0;
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode root = pTree->getRoot();
    // act
    pTree->levelOrder(root);
    // assert
    ASSERT_EQ(valExpected, 1);
}

TEST_F(TreeTest, AddAllAndSecondary_Rebalance_VerifyWithNodeCount) {
    // arrange
    auto pTree = make_shared<Tree>();
    AddAllAndSecondary(pTree);
    pTreeNode origRoot = pTree->getRoot();
    pTree->collectNodeDataInOrder(origRoot, m_nodeData);
    ShowNodeData("InOrder");
    ClearNodeData();
    int beforeCount = pTree->getNodeCount();
    // act
    pTree->rebalance();
    int afterCount = pTree->getNodeCount();
    pTreeNode newRoot = pTree->getRoot();
    pTree->collectNodeDataInOrder(newRoot, m_nodeData);
    ShowNodeData("InOrder");
    pTree->levelOrder(newRoot);
    // assert
    ASSERT_EQ(afterCount, beforeCount);
}

