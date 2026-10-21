#include <map>
#include <string>

#include <gtest/gtest.h>

#include "street_surnames.hpp"

using Counts = std::map<std::string, int>;

TEST(StreetSurnamesTest, Example)
{
    EXPECT_EQ(countSurnamesByStreet(
                  {{"lenina", "ivanov"}, {"gorkogo", "petrov"}, {"lenina", "sidorov"}, {"lenina", "ivanov"}}),
              (Counts{{"gorkogo", 1}, {"lenina", 2}}));
}

TEST(StreetSurnamesTest, NoResidents)
{
    EXPECT_TRUE(countSurnamesByStreet({}).empty());
}
