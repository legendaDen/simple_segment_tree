#include "../segment_tree_lib/segment_tree.h"
#include "test_utils.h"

#include <gtest/gtest.h>

#include <random>
#include <string>
#include <vector>

constexpr int kIterations = 100;
constexpr int kMaxArraySize = 50;
constexpr int kMaxQueries = 100;
constexpr int kMinValue = -100;
constexpr int kMaxValue = 100;

TEST(SegmentTreeStressTest, MatchesNaiveImplementationOnRandomOperations) {
    std::mt19937 rng(12345);

    for (int iter = 0; iter < kIterations; ++iter) {
        SCOPED_TRACE("iteration " + std::to_string(iter));

        int n = std::uniform_int_distribution<int>(1, kMaxArraySize)(rng);
        std::vector<int> values(n);
        for (int& value : values) {
            value = std::uniform_int_distribution<int>(kMinValue, kMaxValue)(rng);
        }

        segment_tree<SegSum> tree(ToSegSum(values));

        int q = std::uniform_int_distribution<int>(1, kMaxQueries)(rng);
        for (int query_idx = 0; query_idx < q; ++query_idx) {
            SCOPED_TRACE("query " + std::to_string(query_idx));

            int type = std::uniform_int_distribution<int>(1, 2)(rng);
            if (type == 1) {
                int pos = std::uniform_int_distribution<int>(0, n - 1)(rng);
                int new_value = std::uniform_int_distribution<int>(kMinValue, kMaxValue)(rng);
                values[pos] = new_value;
                tree.point_update(pos, SegSum(new_value));
            } else {
                int l = std::uniform_int_distribution<int>(0, n - 1)(rng);
                int r = std::uniform_int_distribution<int>(l + 1, n)(rng);
                ASSERT_EQ(tree.range_query(l, r).sum_on_seg, NaiveRangeSum(values, l, r));
            }
        }
    }
}