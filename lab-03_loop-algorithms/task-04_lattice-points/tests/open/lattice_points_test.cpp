#include <gtest/gtest.h>

#include "lattice_points.hpp"

TEST(LatticePointsTest, SmallN)
{
    EXPECT_EQ(countLatticePoints(1), 1); // (0, 0)
    EXPECT_EQ(countLatticePoints(2), 4); // (0, 0), (0, 1), (1, 0), (1, 1)
}

TEST(LatticePointsTest, Ten)
{
    EXPECT_EQ(countLatticePoints(10), 86);
}
