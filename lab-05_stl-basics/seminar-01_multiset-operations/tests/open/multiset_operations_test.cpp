#include <set>

#include <gtest/gtest.h>

#include "multiset_operations.hpp"

TEST(MultisetOperationsTest, Union)
{
    EXPECT_EQ(uniteMultisets({1, 2, 2, 3}, {2, 3, 3, 4}), (std::multiset<int>{1, 2, 2, 3, 3, 4}));
}

TEST(MultisetOperationsTest, Intersection)
{
    EXPECT_EQ(intersectMultisets({1, 2, 2, 3}, {2, 3, 3, 4}), (std::multiset<int>{2, 3}));
}

TEST(MultisetOperationsTest, Difference)
{
    EXPECT_EQ(subtractMultisets({1, 2, 2, 3}, {2, 3, 3, 4}), (std::multiset<int>{1, 2}));
    EXPECT_EQ(subtractMultisets({2, 3, 3, 4}, {1, 2, 2, 3}), (std::multiset<int>{3, 4}));
}
