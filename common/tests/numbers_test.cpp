#include <gtest/gtest.h>

#include <cpplabs/numbers.hpp>

TEST(IsNearlyEqualTest, EqualValues)
{
    EXPECT_TRUE(cpplabs::isNearlyEqual(25.0, 25.0));
}

TEST(IsNearlyEqualTest, RoundingError)
{
    // 0.1 + 0.2 в двоичной системе не равно 0.3 точно
    EXPECT_TRUE(cpplabs::isNearlyEqual(0.1 + 0.2, 0.3));
}

TEST(IsNearlyEqualTest, DifferentValues)
{
    EXPECT_FALSE(cpplabs::isNearlyEqual(1.0, 1.001));
}

TEST(IsNearlyEqualTest, CustomEpsilon)
{
    EXPECT_TRUE(cpplabs::isNearlyEqual(1.0, 1.001, 0.01));
    EXPECT_FALSE(cpplabs::isNearlyEqual(1.0, 1.1, 0.01));
}

TEST(IsNearlyEqualTest, Symmetric)
{
    EXPECT_TRUE(cpplabs::isNearlyEqual(-2.5, -2.5 + 1e-12));
    EXPECT_TRUE(cpplabs::isNearlyEqual(-2.5 + 1e-12, -2.5));
}
