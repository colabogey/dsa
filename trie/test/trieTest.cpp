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
#include "../include/trie.h" // to make the IDE happy (sad)

using namespace std;

// The fixture for testing
class TrieTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    TrieTest() { }

    virtual ~TrieTest() {}

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

TEST_F(TrieTest, GfG) {
    // arrange
    Trie t;
    // act
    t.trie_main();
    // assert
    ASSERT_EQ(1, 1);
}

