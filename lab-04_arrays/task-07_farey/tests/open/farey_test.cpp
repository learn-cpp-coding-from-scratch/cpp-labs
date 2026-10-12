#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "farey.hpp"

TEST(FareyTest, DenominatorsLessThanSix)
{
    EXPECT_EQ(findFareyFractions(6), (std::vector<std::pair<int, int>>{
                                         {1, 5}, {1, 4}, {1, 3}, {2, 5}, {1, 2}, {3, 5}, {2, 3}, {3, 4}, {4, 5}}));
}

TEST(FareyTest, OnlyHalf)
{
    EXPECT_EQ(findFareyFractions(3), (std::vector<std::pair<int, int>>{{1, 2}}));
}
