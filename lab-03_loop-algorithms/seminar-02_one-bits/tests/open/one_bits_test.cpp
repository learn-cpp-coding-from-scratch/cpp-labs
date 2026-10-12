#include <gtest/gtest.h>

#include "one_bits.hpp"

TEST(OneBitsTest, SmallNumbers)
{
    EXPECT_EQ(countOneBits(1), 1); // 1
    EXPECT_EQ(countOneBits(7), 3); // 111
}

TEST(OneBitsTest, Zero)
{
    EXPECT_EQ(countOneBits(0), 0);
}

TEST(OneBitsTest, MinusOne)
{
    EXPECT_EQ(countOneBits(-1), 32); // int — 32 бита
}
