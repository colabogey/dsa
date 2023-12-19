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
#include <time.h>
#include <functional>
#include "mergesort.h"
#include "mergesortit.h"

using namespace std;

// The fixture for testing
class MergerTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    MergerTest() { }

    virtual ~MergerTest() {}

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

    int m_sizeOdd{7};
    int m_valsOdd[7] = {12, 11, 13, 9, 7, 22, 6};

    int m_sizeEven{6};
    int m_valsEven[6] = {12, 11, 13, 9, 7, 22};

};

TEST_F(MergerTest, OddNunberOfElements) {
    // arrange
    auto pMerger = make_unique<Merger>();
    // act
    pMerger->mergeSort(m_valsOdd, 0, (m_sizeOdd - 1));
    pMerger->printArray(m_valsOdd, m_sizeOdd);
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MergerTest, EvenNunberOfElements) {
    // arrange
    auto pMerger = make_unique<Merger>();
    // act
    pMerger->mergeSort(m_valsEven, 0, (m_sizeEven - 1));
    pMerger->printArray(m_valsEven, m_sizeEven);
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MergerTest, It_OddNunberOfElements) {
    // arrange
    int size = 20;
    int ary[size];
    int tmp[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        tmp[i] = ary[i] = (rand() % size);
    }
    auto pMergerIt = make_unique<MergerIt>(size);
    pMergerIt->printArray(ary);
    // act
    pMergerIt->mergeSort(ary, tmp, 0, (size - 1));
    pMergerIt->printArray(ary);
    // assert
    ASSERT_EQ(1, 1);
}

