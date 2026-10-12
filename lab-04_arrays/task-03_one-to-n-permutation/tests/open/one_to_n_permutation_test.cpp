#include <gtest/gtest.h>

#include "one_to_n_permutation.hpp"

TEST(OneToNPermutationTest, Permutation)
{
    EXPECT_TRUE(isOneToNPermutation({3, 1, 2}));
}

TEST(OneToNPermutationTest, Repeated)
{
    EXPECT_FALSE(isOneToNPermutation({1, 2, 2}));
}

TEST(OneToNPermutationTest, OutOfRange)
{
    EXPECT_FALSE(isOneToNPermutation({1, 2, 4}));
}
