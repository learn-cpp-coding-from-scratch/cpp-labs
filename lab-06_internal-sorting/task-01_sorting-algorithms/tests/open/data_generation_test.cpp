#include <vector>

#include <gtest/gtest.h>

#include "data_generation.hpp"

TEST(DataGenerationTest, Ascending)
{
    EXPECT_EQ(generateData(5, {.order = DataOrder::ASCENDING, .randomSetNumber = 0}),
              (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(DataGenerationTest, InputFileName)
{
    EXPECT_EQ(inputFileName(10, {.order = DataOrder::RANDOM, .randomSetNumber = 1}), "input_10_int_random_1.txt");
    EXPECT_EQ(inputFileName(1000, {.order = DataOrder::ASCENDING, .randomSetNumber = 0}),
              "input_1000_int_ascending.txt");
}

TEST(DataGenerationTest, ExperimentDatasets)
{
    const std::vector<Dataset> datasets = experimentDatasets();
    ASSERT_EQ(datasets.size(), 5U);
    EXPECT_EQ(datasets[0].order, DataOrder::ASCENDING);
    EXPECT_EQ(datasets[1].order, DataOrder::DESCENDING);
    EXPECT_EQ(datasets[4].order, DataOrder::RANDOM);
    EXPECT_EQ(datasets[4].randomSetNumber, 3);
}
