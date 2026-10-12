#include <gtest/gtest.h>

#include "permutation_of_array.hpp"

TEST(PermutationOfArrayTest, Permutation)
{
    EXPECT_TRUE(isPermutationOf({3, 1, 2, 1}, {1, 1, 2, 3}));
}

TEST(PermutationOfArrayTest, DifferentCounts)
{
    EXPECT_FALSE(isPermutationOf({1, 2, 2}, {1, 1, 2}));
}
