#include <vector>

#include <gtest/gtest.h>

#include "transpose.hpp"

TEST(TransposeTest, Rectangular)
{
    EXPECT_EQ(transposeMatrix({{1, 2, 3}, {4, 5, 6}}),
              (std::vector<std::vector<int>>{{1, 4}, {2, 5}, {3, 6}}));
}

TEST(TransposeTest, Square)
{
    EXPECT_EQ(transposeMatrix({{1, 2}, {3, 4}}), (std::vector<std::vector<int>>{{1, 3}, {2, 4}}));
}
