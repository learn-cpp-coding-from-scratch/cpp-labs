#include <vector>

#include <gtest/gtest.h>

#include "matrix_product.hpp"

TEST(MatrixProductTest, Rectangular)
{
    // 2 x 3 на 3 x 2
    EXPECT_EQ(multiplyMatrices({{1, 2, 3}, {4, 5, 6}}, {{7, 8}, {9, 10}, {11, 12}}),
              (std::vector<std::vector<int>>{{58, 64}, {139, 154}}));
}

TEST(MatrixProductTest, Identity)
{
    EXPECT_EQ(multiplyMatrices({{1, 2}, {3, 4}}, {{1, 0}, {0, 1}}),
              (std::vector<std::vector<int>>{{1, 2}, {3, 4}}));
}
