#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "multiset_queries.hpp"

TEST(MultisetQueriesTest, Example)
{
    std::multiset<int> numbers{5, 3};
    const std::vector<std::string> results =
        executeQueries(numbers, {"find_min", "add 1", "is_exist 5", "delete 5", "is_exist 5", "find_min"});
    EXPECT_EQ(results, (std::vector<std::string>{"3", "YES", "NO", "1"}));
    EXPECT_EQ(numbers, (std::multiset<int>{1, 3}));
}

TEST(MultisetQueriesTest, EmptyCollection)
{
    std::multiset<int> numbers;
    EXPECT_EQ(executeQueries(numbers, {"find_min"}), (std::vector<std::string>{"EMPTY"}));
}
