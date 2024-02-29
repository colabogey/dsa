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
#include "various.h"
#include "spiral.h"
#include "anagram.h"
#include "sum3.h"

using namespace std;

// The fixture for testing
class VariousTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    VariousTest() {}

    virtual ~VariousTest() {}

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

TEST_F(VariousTest, fib_dp) {
    // arrange
    Various v;
    // act
    int ans = v.fib_dp(10);
    // assert
    ASSERT_EQ(ans, 55);
}

TEST_F(VariousTest, fib_it) {
    // arrange
    Various v;
    // act
    int ans = v.fib_it(10);
    // assert
    ASSERT_EQ(ans, 55);
}

TEST_F(VariousTest, spiral_3_by_3) {
    // arrange
    Spiral s(3, 3);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_8_by_8) {
    // arrange
    Spiral s(8, 8);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_10_by_6) {
    // arrange
    Spiral s(10, 6);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_6_by_10) {
    // arrange
    Spiral s(6, 10);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_5_by_3) {
    // arrange
    Spiral s(5, 3);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_3_by_1) {
    // arrange
    Spiral s(3, 1);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, spiral_1_by_3) {
    // arrange
    Spiral s(1, 3);
    // act
    s.fill();
    s.print();
    // assert
    ASSERT_EQ(55, 55);
}

TEST_F(VariousTest, isAnagramSort_Given_Match) {
    // arrange
    std::string a = "team";
    std::string b = "meat";
    Anagram ag;
    // act
    bool ans = ag.isAnagramSort(a, b);
    // assert
    ASSERT_TRUE(ans);
}

TEST_F(VariousTest, isAnagramSort_Given_No_Match) {
    // arrange
    std::string a = "team";
    std::string b = "zzzz";
    Anagram ag;
    // act
    bool ans = ag.isAnagramSort(a, b);
    // assert
    ASSERT_FALSE(ans);
}

TEST_F(VariousTest, isAnagramUnorderedMap_Given_Match) {
    // arrange
    std::string a = "team";
    std::string b = "meat";
    Anagram ag;
    // act
    bool ans = ag.isAnagramUnorderedMap(a, b);
    // assert
    ASSERT_TRUE(ans);
}

TEST_F(VariousTest, isAnagramUnorderedMap_Given_No_Match) {
    // arrange
    std::string a = "team";
    std::string b = "zzzz";
    Anagram ag;
    // act
    bool ans = ag.isAnagramUnorderedMap(a, b);
    // assert
    ASSERT_FALSE(ans);
}

TEST_F(VariousTest, isAnagramUnorderedMap_Given_Match_With_Repeats) {
    // arrange
    std::string a = "ateam";
    std::string b = "ameat";
    Anagram ag;
    // act
    bool ans = ag.isAnagramUnorderedMap(a, b);
    // assert
    ASSERT_TRUE(ans);
}

TEST_F(VariousTest, isAnagramUnorderedMap_Given_No_Match_With_Repeats) {
    // arrange
    std::string a = "ateam";
    std::string b = "ameaz";
    Anagram ag;
    // act
    bool ans = ag.isAnagramUnorderedMap(a, b);
    // assert
    ASSERT_FALSE(ans);
}

TEST_F(VariousTest, findThreeThatSumToZero_ValuesExist1) {
    // arrange
    std::vector<int> v = {3, 6, 7, 8, -2, -28, 53, -11, 12, 47};
    Sum3ToZero s3;
    // act
    bool ans = s3.canThreeSumToZero(v);
    // assert
    ASSERT_TRUE(ans);
}

TEST_F(VariousTest, findThreeThatSumToZero_ValuesExist2) {
    // arrange
    std::vector<int> v = {-28, 6, 7, 8, -2, 3, 53, -11, 12, 47};
    Sum3ToZero s3;
    // act
    bool ans = s3.canThreeSumToZero(v);
    // assert
    ASSERT_TRUE(ans);
}

TEST_F(VariousTest, findThreeThatSumToZero_ValuesDoNotExist) {
    // arrange
    std::vector<int> v = {-29, 6, 7, 8, -2, 30, 53, -11, 12, 47};
    Sum3ToZero s3;
    // act
    bool ans = s3.canThreeSumToZero(v);
    // assert
    ASSERT_FALSE(ans);
}

