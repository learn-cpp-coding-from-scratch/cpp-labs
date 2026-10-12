#include <vector>

#include <gtest/gtest.h>

#include "set_sizes.hpp"

TEST(SetSizesTest, ThreeSets)
{
    EXPECT_EQ(countSetSizes({5, -2, 0, 3, 3, 3, 0, 7, 0}), (std::vector<int>{2, 3, 1}));
}

TEST(SetSizesTest, Total)
{
    EXPECT_EQ(countAllElements({2, 3, 1}), 6);
}
