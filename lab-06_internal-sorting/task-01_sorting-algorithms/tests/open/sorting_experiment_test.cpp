#include <vector>

#include <gtest/gtest.h>

#include "sorting_experiment.hpp"

TEST(SortingExperimentTest, Algorithms)
{
    const std::vector<SortingAlgorithm> algorithms = sortingAlgorithms();
    ASSERT_EQ(algorithms.size(), 10U);
    EXPECT_EQ(algorithms.front().name, "insertionSort");
    EXPECT_EQ(algorithms.front().title, "вставкой");
    EXPECT_EQ(algorithms.back().name, "mergeSort");
}

TEST(SortingExperimentTest, MeasureSort)
{
    std::vector<int> numbers{3, 1, 2};
    const Measurement measurement = measureSort(&bubbleSort<int>, numbers);
    EXPECT_EQ(numbers, (std::vector<int>{1, 2, 3}));
    EXPECT_GT(measurement.statistics.comparisons, 0);
    EXPECT_GE(measurement.milliseconds, 0.0);
}

TEST(SortingExperimentTest, AverageMeasurement)
{
    const Measurement average = averageMeasurement({{.statistics = {.comparisons = 10, .swaps = 4}, .milliseconds = 1.0},
                                                    {.statistics = {.comparisons = 20, .swaps = 6}, .milliseconds = 3.0}});
    EXPECT_EQ(average.statistics.comparisons, 15);
    EXPECT_EQ(average.statistics.swaps, 5);
    EXPECT_DOUBLE_EQ(average.milliseconds, 2.0);
}
