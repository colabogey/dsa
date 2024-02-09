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
#include <dynamicArray.h>

using namespace std;

// The fixture for testing
class DynamicArrayTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    DynamicArrayTest() { }

    virtual ~DynamicArrayTest() {}

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

TEST_F(DynamicArrayTest, ArrayOfInt_Set_Get) {
    // arrange
    DynamicArray da;
    // act
    da.set(4,7);
    int z = da.get(4);
    // assert
    ASSERT_EQ(z, 7);
}

TEST_F(DynamicArrayTest, say2) {
    // arrange
    DynamicArray da;
    // act
    int x = da.get(346);
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(DynamicArrayTest, say3) {
    // arrange
    DynamicArray da;
    // act
    da.set(329, 12);
    int x = da.get(329);
    // assert
    ASSERT_EQ(x, 12);
}

TEST_F(DynamicArrayTest, sort) {
    // arrange
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,7);
    da.set(4,8);
    da.set(5,1);
    da.sort();
    int l = da.get(0);
    int r = da.get(5);
    // assert
    ASSERT_EQ(l, 1);
    ASSERT_EQ(r, 12);
}

TEST_F(DynamicArrayTest, medianValue_Even) {
    // arrange
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,7);
    da.set(4,8);
    da.set(5,1);
    double m = da.getMedianValue();
    // assert
    ASSERT_EQ(m, 6);
}

TEST_F(DynamicArrayTest, medianValue_Odd) {
    // arrange
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,7);
    da.set(4,8);
    da.set(5,1);
    da.set(6,16);
    double m = da.getMedianValue();
    // assert
    ASSERT_EQ(m, 7);
}

TEST_F(DynamicArrayTest, medianValue_Even_Decimal) {
    // arrange
    double ans = 5.5;
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,6);
    da.set(4,8);
    da.set(5,1);
    double m = da.getMedianValue();
    // assert
    ASSERT_EQ(m, ans);
}

TEST_F(DynamicArrayTest, count) {
    // arrange
    int ans = 6;
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,6);
    da.set(4,8);
    da.set(5,1);
    int c = da.count();
    // assert
    ASSERT_EQ(c, ans);
}

TEST_F(DynamicArrayTest, meanValue) {
    // arrange
    double ans = 35.0/6.0;
    DynamicArray da;
    // act
    da.set(0,3);
    da.set(1,12);
    da.set(2,5);
    da.set(3,6);
    da.set(4,8);
    da.set(5,1);
    double c = da.getMeanValue();
    // assert
    ASSERT_EQ(c, ans);
}

