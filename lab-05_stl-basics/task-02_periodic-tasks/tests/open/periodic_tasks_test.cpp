#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "periodic_tasks.hpp"

using Executions = std::vector<std::pair<int, int>>;

TEST(PeriodicTasksTest, Example)
{
    EXPECT_EQ(findFirstExecutions({2, 3}, 6), (Executions{{0, 1}, {0, 2}, {2, 1}, {3, 2}, {4, 1}, {6, 1}}));
}

TEST(PeriodicTasksTest, OneTask)
{
    EXPECT_EQ(findFirstExecutions({5}, 3), (Executions{{0, 1}, {5, 1}, {10, 1}}));
}
