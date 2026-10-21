#include <gtest/gtest.h>

#include "distinct_strings.hpp"

TEST(DistinctStringsTest, WithRepeats)
{
    EXPECT_EQ(countDistinctStrings({"abc", "ab", "abc", "x"}), 3);
}

TEST(DistinctStringsTest, AllDifferent)
{
    EXPECT_EQ(countDistinctStrings({"a", "b", "c"}), 3);
}
