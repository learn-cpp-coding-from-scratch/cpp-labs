#include <vector>

#include <gtest/gtest.h>

#include "remove_zeros.hpp"

TEST(RemoveZerosTest, ZerosInside)
{
    std::vector<int> numbers{0, 5, 0, 0, -3, 7};
    removeZeros(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{5, -3, 7}));
}

TEST(RemoveZerosTest, NoZeros)
{
    std::vector<int> numbers{1, 2, 3};
    removeZeros(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{1, 2, 3}));
}
