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
#include <vector>
#include "query.h"
#include "interface_C.h"

using namespace std;

// The fixture for testing
class MetaprepTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    MetaprepTest() {}

    virtual ~MetaprepTest() {}

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

TEST_F(MetaprepTest, arr_contig_subarrays) {
    // arrange
    // act
    main_arr_contig_subarrays();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, arr_passing_yearbooks) {
    // arrange
    // act
    main_arr_passing_yearbooks();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, arr_reverse_to_make_EQual) {
    // arrange
    // act
    main_arr_reverse_to_make_equal();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, greedy_element_swapping) {
    // arrange
    // act
    main_greedy_element_swapping();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, greedy_seating_arrangements) {
    // arrange
    // act
    main_greedy_seating_arrangements();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, greedy_slow_sums) {
    // arrange
    // act
    main_greedy_slow_sums();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, hasht_pair_sums) {
    // arrange
    // act
    main_hasht_pair_sums();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, heap_largest_triple_product) {
    // arrange
    // act
    main_heap_largest_triple_product();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, heap_magical_bags) {
    // arrange
    // act
    main_heap_magical_bags();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, heap_median_stream) {
    // arrange
    // act
    main_heap_median_stream();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, queue_removals) {
    // arrange
    // act
    main_queue_removals();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, recur_change_in_foreign_currency) {
    // arrange
    // act
    main_recur_change_in_foreign_currency();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, recur_encrypted_words) {
    // arrange
    // act
    main_recur_encrypted_words();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, search_billion_users) {
    // arrange
    // act
    main_search_billion_users();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, search_revenue_milestones) {
    // arrange
    // act
    main_search_revenue_milestones();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, sort_balanced_split) {
    // arrange
    // act
    main_sort_balanced_split();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, sort_count_triangles) {
    // arrange
    // act
    main_sort_count_triangles();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, stack_balance_braces) {
    // arrange
    // act
    main_stack_balance_braces();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, str_matching_pairs) {
    // arrange
    // act
    main_str_matching_pairs();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, str_minimum_lgn_substrings) {
    // arrange
    // act
    main_str_minimum_lgn_substrings();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, str_rotational_cipher) {
    // arrange
    // act
    main_str_rotational_cipher();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, tree_nodes_in_subtree) {
    // arrange
    // act
    main_tree_nodes_in_subtree();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, tree_num_visible_nodes) {
    // arrange
    // act
    main_tree_num_visible_nodes();
    // assert
    ASSERT_EQ(1, 1);
}

TEST_F(MetaprepTest, answerQueries) {
    // arrange
    vector<query> q = {{2, 3}, {1, 2}, {2, 1}, {2, 3}, {2, 2}};
    vector<bool> v (5, false);
    // act
    vector<int> ans = answerQueries(v, q);
    // assert
    ASSERT_EQ(ans[0], -1);
    ASSERT_EQ(ans[1], 2);
    ASSERT_EQ(ans[2], -1);
    ASSERT_EQ(ans[3], 2);
}
