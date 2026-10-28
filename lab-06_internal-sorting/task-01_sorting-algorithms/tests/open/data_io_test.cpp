#include <sstream>
#include <vector>

#include <gtest/gtest.h>

#include "data_io.hpp"

TEST(DataIoTest, ReadNumbers)
{
    std::istringstream in("3 -1\n2");
    EXPECT_EQ(readNumbers<int>(in), (std::vector<int>{3, -1, 2}));
}

TEST(DataIoTest, WriteNumbers)
{
    std::ostringstream out;
    writeNumbers(out, std::vector<int>{3, -1, 2});
    EXPECT_EQ(out.str(), "3 -1 2\n");
}
