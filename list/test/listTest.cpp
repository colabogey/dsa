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
#include <linkedList.h>

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

TEST_F(LinkedListTest, InsertNode_VerifyItemFound_ByNodeCount) {
    // arrange
    string data = "Lucky";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data);
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(LinkedListTest, InsertNode_VerifyItemFound_ByValue) {
    // arrange
    string data = "Lucky";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data);
    std::string rVal = pLinkedList->get(data);
    // assert
    ASSERT_STREQ(data.c_str(), rVal.c_str());
}

TEST_F(LinkedListTest, RemoveFirstNode_Verify_ByNodeCount) {
    // arrange
    string data1 = "Lucky";
    string data2 = "Chance";
    string data3 = "Bogey";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data1);
    pLinkedList->add(data2);
    pLinkedList->add(data3);
    pLinkedList->remove(data1);
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveMiddle_Verify_ByNodeCount) {
    // arrange
    string data1 = "Lucky";
    string data2 = "Chance";
    string data3 = "Bogey";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data1);
    pLinkedList->add(data2);
    pLinkedList->add(data3);
    pLinkedList->remove(data2);
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveLast_Verify_ByNodeCount) {
    // arrange
    string data1 = "Lucky";
    string data2 = "Chance";
    string data3 = "Bogey";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data1);
    pLinkedList->add(data2);
    pLinkedList->add(data3);
    pLinkedList->remove(data3);
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 2);
}

TEST_F(LinkedListTest, RemoveAllAdded_Verify_ByNodeCount) {
    // arrange
    string data1 = "Lucky";
    string data2 = "Chance";
    string data3 = "Bogey";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data1);
    pLinkedList->add(data2);
    pLinkedList->add(data3);
    pLinkedList->remove(data2);
    pLinkedList->remove(data1);
    pLinkedList->remove(data3);
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 0);
}

TEST_F(LinkedListTest, RemoveNonExistent_Verify_ByNodeCount) {
    // arrange
    string data1 = "Lucky";
    string data2 = "Chance";
    string data3 = "Bogey";
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->add(data1);
    pLinkedList->add(data2);
    pLinkedList->add(data3);
    pLinkedList->remove("some dog");
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 3);
}

TEST_F(LinkedListTest, RemoveFromEmptyList_Verify_ByNodeCount) {
    // arrange
    auto pLinkedList = make_unique<LinkedList>();
    // act
    pLinkedList->remove("nuttin");
    int count = pLinkedList->getNodeCount();
    // assert
    ASSERT_EQ(count, 0);
}

