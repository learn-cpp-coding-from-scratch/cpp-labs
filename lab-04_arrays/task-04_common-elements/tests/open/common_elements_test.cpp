#include <gtest/gtest.h>

#include "common_elements.hpp"

TEST(CommonElementsTest, SomeCommon)
{
    EXPECT_EQ(countCommonElements({1, 3, 5, 7}, {2, 3, 4, 7, 9}), 2);
}

TEST(CommonElementsTest, NoCommon)
{
    EXPECT_EQ(countCommonElements({1, 3, 5}, {2, 4, 6}), 0);
}
