#include <vector>

#include <gtest/gtest.h>

#include "sorting.hpp"

TEST(BubbleSortTest, Unsorted)
{
    std::vector<int> numbers{3, -1, 2, -1, 0};
    bubbleSort(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{-1, -1, 0, 2, 3}));
}

TEST(ShakerSortTest, Unsorted)
{
    std::vector<int> numbers{3, -1, 2, -1, 0};
    shakerSort(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{-1, -1, 0, 2, 3}));
}

TEST(SelectionSortTest, Unsorted)
{
    std::vector<int> numbers{3, -1, 2, -1, 0};
    selectionSort(numbers);
    EXPECT_EQ(numbers, (std::vector<int>{-1, -1, 0, 2, 3}));
}
