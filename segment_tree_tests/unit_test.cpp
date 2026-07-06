#include "../segment_tree_lib/segment_tree.h"
#include "test_utils.h"

#include <gtest/gtest.h>

TEST(SegmentTreeUnitTest, RepeatedUpdatesToSameElementKeepLastValue) {
    segment_tree<SegSum> tree(ToSegSum({1, 2, 3, 4, 5, 6, 7}));

    for (int new_value : {1, 2, 3, 4, 5, 6, 7, 8, 1}) {
        tree.point_update(0, SegSum(new_value));
    }

    EXPECT_EQ(tree.range_query(0, 1).sum_on_seg, 1);
}

TEST(SegmentTreeUnitTest, PointUpdatesReflectInSingleElementQueries) {
    segment_tree<SegSum> tree(ToSegSum({1, 2, 3, 4, 5}));

    tree.point_update(0, SegSum(5));
    tree.point_update(1, SegSum(4));
    tree.point_update(2, SegSum(3));
    tree.point_update(3, SegSum(2));
    tree.point_update(4, SegSum(1));

    EXPECT_EQ(tree.range_query(0, 1).sum_on_seg, 5);
    EXPECT_EQ(tree.range_query(1, 2).sum_on_seg, 4);
    EXPECT_EQ(tree.range_query(2, 3).sum_on_seg, 3);
    EXPECT_EQ(tree.range_query(3, 4).sum_on_seg, 2);
    EXPECT_EQ(tree.range_query(4, 5).sum_on_seg, 1);
}

TEST(SegmentTreeUnitTest, RangeQuerySumsMultipleElements) {
    segment_tree<SegSum> tree(ToSegSum({1, 2, 3, 4, 5, 6, 7}));

    EXPECT_EQ(tree.range_query(0, 7).sum_on_seg, 28);
    EXPECT_EQ(tree.range_query(1, 4).sum_on_seg, 2 + 3 + 4);
    EXPECT_EQ(tree.range_query(3, 7).sum_on_seg, 4 + 5 + 6 + 7);
}