#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "sorting_algorithms.hpp"

namespace {

// Сортировка для обоих типов элементов; name — имя функции: по нему тесты запускаются отдельно
struct SortCase {
    std::string name;
    SortStatistics (*sortInts)(std::vector<int>&);
    SortStatistics (*sortDoubles)(std::vector<double>&);
};

const std::vector<SortCase> SORT_CASES{
    {"insertionSort", &insertionSort<int>, &insertionSort<double>},
    {"shellSort", &shellSort<int>, &shellSort<double>},
    {"bubbleSort", &bubbleSort<int>, &bubbleSort<double>},
    {"oddEvenSort", &oddEvenSort<int>, &oddEvenSort<double>},
    {"cocktailSort", &cocktailSort<int>, &cocktailSort<double>},
    {"combSort", &combSort<int>, &combSort<double>},
    {"selectionSort", &selectionSort<int>, &selectionSort<double>},
    {"doubleSelectionSort", &doubleSelectionSort<int>, &doubleSelectionSort<double>},
    {"quickSort", &quickSort<int>, &quickSort<double>},
    {"mergeSort", &mergeSort<int>, &mergeSort<double>},
};

class SortingAlgorithmsTest : public testing::TestWithParam<SortCase> {};

} // namespace

TEST_P(SortingAlgorithmsTest, Example)
{
    std::vector<int> numbers{3, -1, 2, -1};
    GetParam().sortInts(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{-1, -1, 2, 3}));
}

TEST_P(SortingAlgorithmsTest, Doubles)
{
    std::vector<double> numbers{2.5, -0.5, 1.0, 0.0};
    GetParam().sortDoubles(numbers);
    EXPECT_EQ(numbers, (std::vector<double>{-0.5, 0.0, 1.0, 2.5}));
}

TEST_P(SortingAlgorithmsTest, EmptyAndSingle)
{
    std::vector<int> empty;
    GetParam().sortInts(empty);
    EXPECT_TRUE(empty.empty());

    std::vector<int> single{7};
    GetParam().sortInts(single);
    EXPECT_EQ(single, std::vector<int>{7});
}

TEST_P(SortingAlgorithmsTest, CountsOperations)
{
    std::vector<int> numbers{2, 1};
    const SortStatistics statistics = GetParam().sortInts(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{1, 2}));
    EXPECT_GT(statistics.comparisons, 0);
    EXPECT_GT(statistics.swaps, 0);
}

// Имена тестов: Sorts/SortingAlgorithmsTest.Example/bubbleSort — запуск одной сортировки: ctest -R bubbleSort
INSTANTIATE_TEST_SUITE_P(Sorts, SortingAlgorithmsTest, testing::ValuesIn(SORT_CASES),
                         [](const testing::TestParamInfo<SortCase>& info) { return info.param.name; });
