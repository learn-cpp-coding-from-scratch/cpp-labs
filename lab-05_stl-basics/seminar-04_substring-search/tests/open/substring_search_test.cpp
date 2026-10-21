#include <vector>

#include <gtest/gtest.h>

#include "substring_search.hpp"

TEST(SubstringSearchTest, Example)
{
    EXPECT_EQ(findSubstringPositions({{"banana", "ana"}, {"banana", "nab"}, {"abc", "c"}}),
              (std::vector<int>{1, -1, 2}));
}

TEST(SubstringSearchTest, NoPairs)
{
    EXPECT_TRUE(findSubstringPositions({}).empty());
}
