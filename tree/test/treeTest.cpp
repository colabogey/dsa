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
    }

    // Objects declared here can be used by all tests.
    //

    int m_size{9};
    int m_vals[9] = {50, 40, 35, 27, 60, 42, 16, 3, 90 };
};

TEST_F(TreeTest, InsertOne_VerifyItemFound_ByNodeCount) {
    // arrange
    int toAdd = 1;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->add(m_vals[spot]);
        spot++;
    }
    int count = pTree->getNodeCount();
    pTreeNode root = pTree->getRoot();
    // assert
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, InsertTwo_VerifyItemFound_ByNodeCount) {
    // arrange
    int toAdd = 2;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->add(m_vals[spot]);
        spot++;
    }
    int count = pTree->getNodeCount();
    pTreeNode root = pTree->getRoot();
    // assert
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, InsertAll_GetValue_VerifyItemFound_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = m_vals[5];
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->add(m_vals[spot]);
        spot++;
    }
    int count = pTree->getNodeCount();
    rVal = pTree->get(keyToGet);
    // assert
    ASSERT_EQ(rVal, m_vals[5]);
}

TEST_F(TreeTest, InsertAllRecursive_VerifyItemFound_ByNodeCount) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->addRecursive(m_vals[spot]);
        spot++;
    }
    int count = pTree->getNodeCount();
    pTreeNode root = pTree->getRoot();
    // assert
    //pTree->show(root);
    ASSERT_EQ(count, toAdd);
}

TEST_F(TreeTest, InsertAll_GetBogusValue_VerifyItemFound_ByKey) {
    // arrange
    int rVal = -1;
    int keyToGet = 697;
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->add(m_vals[spot]);
        spot++;
    }
    int count = pTree->getNodeCount();
    rVal = pTree->get(keyToGet);
    // assert
    ASSERT_EQ(rVal, -1);
}

TEST_F(TreeTest, InsertAll_ThenGetDepth) {
    // arrange
    int toAdd = m_size;
    int spot = 0;
    auto pTree = make_unique<Tree>();
    // act
    for(int i = toAdd; i > 0; i--)
    {
        pTree->addRecursive(m_vals[spot]);
        spot++;
    }
    int depth = pTree->getDepth();
    
    // assert
    //pTree->show(root);
    ASSERT_EQ(depth, 6);
}

