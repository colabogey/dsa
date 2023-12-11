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
};

TEST_F(TreeTest, InsertOne_VerifyItemFound_ByNodeCount) {
    // arrange
    int key = 50;
    auto pTree = make_unique<Tree>();
    // act
    pTree->add(key);
    int count = pTree->getNodeCount();
    pTreeNode root = pTree->getRoot();
    // assert
    pTree->show(root);
    ASSERT_EQ(count, 1);
}

TEST_F(TreeTest, InsertTwo_VerifyItemFound_ByNodeCount) {
    // arrange
    int key1 = 50;
    int key2 = 40;
    auto pTree = make_unique<Tree>();
    // act
    pTree->add(key1);
    pTree->add(key2);
    int count = pTree->getNodeCount();
    pTreeNode root = pTree->getRoot();
    // assert
    pTree->show(root);
    ASSERT_EQ(count, 2);
}

