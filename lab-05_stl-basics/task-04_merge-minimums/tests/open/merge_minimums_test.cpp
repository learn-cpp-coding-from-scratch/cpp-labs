#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "merge_minimums.hpp"

using Steps = std::vector<std::pair<int, int>>;

TEST(MergeMinimumsTest, Example)
{
    EXPECT_EQ(mergeMinimums({4, 1, 3, 2}), (Steps{{3, 4}, {4, 6}, {10, 10}}));
}

TEST(MergeMinimumsTest, OneNumber)
{
    EXPECT_TRUE(mergeMinimums({7}).empty());
}
