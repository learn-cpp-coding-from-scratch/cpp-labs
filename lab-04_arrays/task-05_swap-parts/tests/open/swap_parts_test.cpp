#include <vector>

#include <gtest/gtest.h>

#include "swap_parts.hpp"

TEST(SwapPartsTest, Example)
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    swapParts(numbers, 2);
    EXPECT_EQ(numbers, (std::vector<int>{3, 4, 5, 6, 1, 2}));
}

TEST(SwapPartsTest, EqualParts)
{
    std::vector<int> numbers{1, 2, 3, 4};
    swapParts(numbers, 2);
    EXPECT_EQ(numbers, (std::vector<int>{3, 4, 1, 2}));
}
