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
#include <arrayShifter.h>

using namespace std;

// The fixture for testing
class ArrayShiftTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    ArrayShiftTest() {
        // You can do set-up work for each test here.
        int i;
        for(int i = 0; i < m_arySize; i++)
        {
            m_ary[i] = i + 1;
        }
    }

    virtual ~ArrayShiftTest() {}

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
    int m_ary[6] = {1, 2, 3, 4, 5 ,6 } ;
    int m_arySize = sizeof(m_ary)/sizeof(int);

};

TEST_F(ArrayShiftTest, ArrayShiftRight_One) {
    // arrange
    int shiftAmount = 1;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftRight(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[m_arySize - 1]);
}

TEST_F(ArrayShiftTest, ArrayShiftRight_One_WithMultipleOfShiftAmount) {
    // arrange
    int shiftAmount = (m_arySize * 3) + 1;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftRight(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[m_arySize - 1]);
}

TEST_F(ArrayShiftTest, ArrayShiftRight_Zero) {
    // arrange
    int shiftAmount = 0;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftRight(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[0]);
}

TEST_F(ArrayShiftTest, ArrayShiftRight_Zero_WithMultipleOfShiftAmount) {
    // arrange
    int shiftAmount = (m_arySize * 3);
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftRight(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[0]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_One) {
    // arrange
    int shiftAmount = 1;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftLeft(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[1]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_One_WithMultipleOfShiftAmount) {
    // arrange
    int shiftAmount = (m_arySize * 3) + 1;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftLeft(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[1]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_Zero) {
    // arrange
    int shiftAmount = 0;
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftLeft(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[0]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_Zero_WithMultipleOfShiftAmount) {
    // arrange
    int shiftAmount = (m_arySize * 3);
    int aryResult[m_arySize];
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->Init(m_ary, m_arySize);
    // act
    aShifter->ShiftLeft(shiftAmount);
    aShifter->MakeNewArray(aryResult);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[0]);
}

TEST_F(ArrayShiftTest, ArrayShiftRight_One_Os) {
    // arrange
    int shiftAmount = 1;
    int aryResult[m_arySize] = {1, 2, 3, 4, 5 ,6 };
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->InitOs(m_arySize);
    // act
    aShifter->ShiftRightOs(aryResult, shiftAmount);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[m_arySize - 1]);
}

TEST_F(ArrayShiftTest, ArrayShiftRight_One_WithMultipleOfShiftAmount_Os) {
    // arrange
    int shiftAmount = (m_arySize * 4) + 1;
    int aryResult[m_arySize] = {1, 2, 3, 4, 5 ,6 };
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->InitOs(m_arySize);
    // act
    aShifter->ShiftRightOs(aryResult, shiftAmount);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[m_arySize - 1]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_One_Os) {
    // arrange
    int shiftAmount = 1;
    int aryResult[m_arySize] = {1, 2, 3, 4, 5 ,6 };
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->InitOs(m_arySize);
    // act
    aShifter->ShiftLeftOs(aryResult, shiftAmount);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[1]);
}

TEST_F(ArrayShiftTest, ArrayShiftLeft_One_WithMultipleOfShiftAmount_Os) {
    // arrange
    int shiftAmount = (m_arySize * 4) + 1;
    int aryResult[m_arySize] = {1, 2, 3, 4, 5 ,6 };
    auto aShifter = std::make_unique<ArrayShifter>();
    aShifter->InitOs(m_arySize);
    // act
    aShifter->ShiftLeftOs(aryResult, shiftAmount);
    // assert
    ASSERT_EQ(aryResult[0], m_ary[1]);
}
