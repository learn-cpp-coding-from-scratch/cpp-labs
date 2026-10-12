#include <array>

#include <gtest/gtest.h>

#include "sign_order.hpp"

TEST(SignOrderTest, Mixed)
{
    std::array<int, ARRAY_SIZE> numbers{3, -1, 0, -5, 2, 0, 7, -2, 0, 1};
    arrangeBySign(numbers);
    EXPECT_EQ(numbers, (std::array<int, ARRAY_SIZE>{-1, -5, -2, 0, 0, 0, 3, 2, 7, 1}));
}

TEST(SignOrderTest, AlreadyArranged)
{
    std::array<int, ARRAY_SIZE> numbers{-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    arrangeBySign(numbers);
    EXPECT_EQ(numbers, (std::array<int, ARRAY_SIZE>{-4, -3, -2, -1, 0, 1, 2, 3, 4, 5}));
}
