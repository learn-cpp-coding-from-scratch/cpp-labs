#include <gtest/gtest.h>

#ifdef CPPLABS_USE_MODULES
import missing_digit;
#else
#include "missing_digit.hpp"
#endif

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
