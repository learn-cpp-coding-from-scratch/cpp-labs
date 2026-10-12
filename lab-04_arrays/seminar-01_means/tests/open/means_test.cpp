#include <vector>

#include <gtest/gtest.h>

#include "means.hpp"

TEST(MeansTest, PositiveAndNegative)
{
    const auto [geometricMean, arithmeticMean] = findMeans({1.0, 4.0, -2.0, -4.0});
    EXPECT_NEAR(geometricMean, 2.0, 1e-9);
    EXPECT_NEAR(arithmeticMean, -3.0, 1e-9);
}

TEST(MeansTest, ZerosAreSkipped)
{
    const auto [geometricMean, arithmeticMean] = findMeans({0.0, 2.0, 0.0, 8.0, -5.0});
    EXPECT_NEAR(geometricMean, 4.0, 1e-9);
    EXPECT_NEAR(arithmeticMean, -5.0, 1e-9);
}
