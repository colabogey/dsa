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

#include <shifterNoIndex.h>
#include <shifterWithIndex.h>
#include <functional>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

using namespace std;

// The fixture for testing
class ShifterTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    ShifterTest() {
        // You can do set-up work for each test here.
        int i;
        for (int i = 0; i < m_sz; i++) {
            m_a[i] = i + 1;
        }
    }

    virtual ~ShifterTest() {}

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        //
        std::copy(std::begin(m_a), std::end(m_a), std::begin(m_b));
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests.
    //
    int m_a[6] = {1, 2, 3, 4, 5, 6};
    int m_b[6] = {1, 2, 3, 4, 5, 6};
    int m_sz = sizeof(m_a) / sizeof(int);
};

TEST_F(ShifterTest, NI_ShiftRight_Four_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[m_sz] = {3, 4, 5, 6, 1, 2};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(aryAnswer[i], m_a[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftRight_Four_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3) + 4;
    int aryAnswer[m_sz] = {3, 4, 5, 6, 1, 2};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftRight_Four_ArraySize_One_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[1] = {1};
    auto aShifter = std::make_unique<ShifterNoIndex>(m_a, 1, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < 1; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftRight_Zero_WithIndex) {
    // arrange
    int shiftAmount = 0;
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftRight_Zero_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3);
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftLeft_One_WithIndex) {
    // arrange
    int shiftAmount = 1;
    int aryAnswer[m_sz] = {2, 3, 4, 5, 6, 1};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftLeft_Four_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[m_sz] = {5, 6, 1, 2, 3, 4};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftLeft_One_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3) + 1;
    int aryAnswer[m_sz] = {2, 3, 4, 5, 6, 1};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftLeft_Zero_WithIndex) {
    // arrange
    int shiftAmount = 0;
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, NI_ShiftLeft_Zero_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3);
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterNoIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftRight_Four_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[m_sz] = {3, 4, 5, 6, 1, 2};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(aryAnswer[i], m_a[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftRight_Four_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3) + 4;
    int aryAnswer[m_sz] = {3, 4, 5, 6, 1, 2};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftRight_Four_ArraySize_One_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[1] = {1};
    auto aShifter = std::make_unique<ShifterWithIndex>(m_a, 1, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < 1; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftRight_Zero_WithIndex) {
    // arrange
    int shiftAmount = 0;
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftRight_Zero_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3);
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftRight();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftLeft_One_WithIndex) {
    // arrange
    int shiftAmount = 1;
    int aryAnswer[m_sz] = {2, 3, 4, 5, 6, 1};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftLeft_Four_WithIndex) {
    // arrange
    int shiftAmount = 4;
    int aryAnswer[m_sz] = {5, 6, 1, 2, 3, 4};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftLeft_One_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3) + 1;
    int aryAnswer[m_sz] = {2, 3, 4, 5, 6, 1};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftLeft_Zero_WithIndex) {
    // arrange
    int shiftAmount = 0;
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}

TEST_F(ShifterTest, WI_ShiftLeft_Zero_WithMultipleOfShiftAmount_WithIndex) {
    // arrange
    int shiftAmount = (m_sz * 3);
    int aryAnswer[m_sz] = {1, 2, 3, 4, 5, 6};
    auto aShifter =
        std::make_unique<ShifterWithIndex>(m_a, m_sz, shiftAmount);
    // act
    aShifter->ShiftLeft();
    // assert
    for (int i = 0; i < m_sz; i++) {
        ASSERT_EQ(m_a[i], aryAnswer[i]);
    }
}
