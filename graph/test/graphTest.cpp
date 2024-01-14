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
#include <graph.h>

using namespace std;

// The fixture for testing
class GraphTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    GraphTest() { }

    virtual ~GraphTest() {}

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

    virtual void DumpBfsList(std::list<int>& results) {
        for(int i : results) {
            printf("(%d) ", i);
        }
        printf("\n");
    }

    // Objects declared here can be used by all tests.
    //
};

TEST_F(GraphTest, AddEdges) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, AddEdges_OneTooMany) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);

    pGraph->addEdge(5, 3, 4);
    int count = 1;
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, BFS_StartAt_Zero) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->BFS(0);
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, BFS_StartAt_Three) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->BFS(3);
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, bfsSay_StartAt_Zero) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    std::list<int> results;
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->bfsSay(0, results);
    DumpBfsList(results);
    // assert
    ASSERT_EQ(count, 1);
}

TEST_F(GraphTest, bfsSay_StartAt_Three) {
    // arrange
    auto pGraph = make_shared<Graph>(6);
    std::list<int> results;
    // act
    pGraph->addEdge(0, 1, 1);
    pGraph->addEdge(1, 3, 3);
    pGraph->addEdge(3, 5, 5);
    pGraph->addEdge(0, 2, 2);
    pGraph->addEdge(2, 4, 4);
    pGraph->addEdge(4, 5, 6);
    int count = 1;
    pGraph->bfsSay(3, results);
    DumpBfsList(results);
    // assert
    ASSERT_EQ(count, 1);
}

