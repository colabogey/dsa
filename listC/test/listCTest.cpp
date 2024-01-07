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

#include <linkedList.h>
#include <listInterface.h>

using namespace std;

// The fixture for testing
class LinkedListTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    LinkedListTest() { }

    virtual ~LinkedListTest() {}

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

TEST_F(LinkedListTest, InsertNode_Verify_NodeCount) {
    // arrange
    const char data[] = {"Lucky"};
    auto pll = createLinkedList();
    // act
    addListNode(pll, data);
    int count = getNodeCount(pll);
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(LinkedListTest, InsertNode_GetValidFirstItem_Verify_DataValue) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    const char* rVal = getListNodeData(pll, data1);
    // assert
    ASSERT_STREQ(data1, rVal);
}

TEST_F(LinkedListTest, InsertNode_GetValidSecondItem_Verify_DataValue) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    const char* rVal = getListNodeData(pll, data2);
    // assert
    ASSERT_STREQ(data2, rVal);
}

TEST_F(LinkedListTest, InsertNode_GetValidLastItem_Verify_DataValue) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    const char* rVal = getListNodeData(pll, data3);
    // assert
    ASSERT_STREQ(data3, rVal);
}

TEST_F(LinkedListTest, InsertNothing_GetItem_Verify_DataValueIsNull) {
    // arrange
    const char data[] = {"Lucky"};
    auto pll = createLinkedList();
    // act
    const char* rVal = getListNodeData(pll, data);
    // assert
    ASSERT_EQ(nullptr, rVal);
}

TEST_F(LinkedListTest, InsertNode_GetInValidItem_Verify_DataValueIsNull) {
    // arrange
    const char data[] = {"Lucky"};
    const char invalid[] = {"xyx"};
    auto pll = createLinkedList();
    addListNode(pll, data);
    // act
    const char* rVal = getListNodeData(pll, invalid);
    // assert
    ASSERT_EQ(nullptr, rVal);
}

TEST_F(LinkedListTest, RemoveFirst_Verify_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    removeListNode(pll, data1);
    int count = getNodeCount(pll);
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveLast_Verify_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    removeListNode(pll, data3);
    int count = getNodeCount(pll);
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveMiddle_Verify_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    removeListNode(pll, data2);
    int count = getNodeCount(pll);
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveFirst_Verify_Return_And_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    bool rVal = removeListNode(pll, data1);
    int count = getNodeCount(pll);
    // assert
    EXPECT_TRUE(rVal);
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveLast_Verify_Return_And_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    bool rVal = removeListNode(pll, data1);
    int count = getNodeCount(pll);
    // assert
    EXPECT_TRUE(rVal);
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveMiddle_Verify_Return_And_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    bool rVal = removeListNode(pll, data1);
    int count = getNodeCount(pll);
    // assert
    EXPECT_TRUE(rVal);
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, ClearLinkedList_Verify_By_NodeCount) {
    // arrange
    const char data1[] = {"Lucky"};
    const char data2[] = {"Chance"};
    const char data3[] = {"Bogey"};
    auto pll = createLinkedList();
    addListNode(pll, data1);
    addListNode(pll, data2);
    addListNode(pll, data3);
    // act
    clearLinkedList(pll);
    int count = getNodeCount(pll);
    // assert
    ASSERT_EQ(count, 0);
}

