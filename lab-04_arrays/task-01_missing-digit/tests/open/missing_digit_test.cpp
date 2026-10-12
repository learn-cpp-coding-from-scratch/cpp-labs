#include <gtest/gtest.h>

#include "missing_digit.hpp"

TEST(MissingDigitTest, ZeroMissing)
{
    EXPECT_EQ(findSmallestMissingDigit(1234), 0);
}

TEST(MissingDigitTest, DigitInMiddleMissing)
{
    EXPECT_EQ(findSmallestMissingDigit(1023), 4);
}

TEST(MissingDigitTest, AllDigitsPresent)
{
    EXPECT_EQ(findSmallestMissingDigit(1023456789), -1);
}
