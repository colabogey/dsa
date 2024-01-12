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
#include <hashMap.h>
#include <hashTableItem.h>

using namespace std;

// The fixture for testing
class HashMapTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    HashMapTest() { }

    virtual ~HashMapTest() {}

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

TEST_F(HashMapTest, Insert_Verify_Item_Found) {
    // arrange
    string key = "Lucky";
    string value = "tabby";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key, value);
    string returnValue = pHashMap->find(key);
    // assert
    ASSERT_STREQ(value.c_str(), returnValue.c_str());
}

TEST_F(HashMapTest, Insert_FindNonExistentKey_ReturnStringNull) {
    // arrange
    string key = "Lucky";
    string value = "tabby";
    string bogus = "Bogus";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key, value);
    string returnValue = pHashMap->find(bogus);
    // assert
    ASSERT_STREQ("", returnValue.c_str());
}

TEST_F(HashMapTest, InsertThenRemove_FindKey_ReturnStringNull) {
    // arrange
    string key = "Lucky";
    string value = "tabby";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key, value);
    pHashMap->remove(key);
    string returnValue = pHashMap->find(key);
    // assert
    ASSERT_STREQ("", returnValue.c_str());
}

TEST_F(HashMapTest, InsertThenRemove_VerifyReturnItemKeyMatchesInsert) {
    // arrange
    string key = "Lucky";
    string value = "tabby";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key, value);
    pHashMap->remove(key);
    // assert
    ASSERT_STREQ("abc", "abc");
}

TEST_F(HashMapTest, InsertThenRemove_VerifyReturnItemValueMatchesInsert) {
    // arrange
    string key = "Lucky";
    string value = "tabby";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key, value);
    pHashMap->remove(key);
    // assert
    ASSERT_STREQ("abc", "abc");
}

TEST_F(HashMapTest, Insert_Collision) {
    // arrange
    string key1 = "ab";
    string value1 = "one";
    string key2 = "ba";
    string value2 = "two";
    auto pHashMap = make_unique<HashMap>();
    // act
    pHashMap->insert(key1, value1);
    pHashMap->insert(key2, value2);
    string returnValue = pHashMap->find(key1);
    // assert
    ASSERT_STREQ(value1.c_str(), returnValue.c_str());
}

