#include <vector>

#include <gtest/gtest.h>

#include "reverse.hpp"

TEST(ReverseTest, EvenSize)
{
    std::vector<int> numbers{1, 2, 3, 4};
    reverseElements(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{4, 3, 2, 1}));
}

TEST(ReverseTest, OddSize)
{
    std::vector<int> numbers{1, 2, 3, 4, 5};
    reverseElements(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{5, 4, 3, 2, 1}));
}
