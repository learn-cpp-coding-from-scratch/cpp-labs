#include <stdexcept>

#include <gtest/gtest.h>

#include "array.hpp"
#include "array_service.hpp"

TEST(ArrayServiceTest, Sum)
{
    EXPECT_EQ(ArrayService::sum(Array<int>{1, 2, 3}), 6);
    EXPECT_EQ(ArrayService::sum(Array<int>{}), 0);
    EXPECT_DOUBLE_EQ(ArrayService::sum(Array<double>{0.5, 0.25}), 0.75);
}

TEST(ArrayServiceTest, Average)
{
    EXPECT_DOUBLE_EQ(ArrayService::average(Array<int>{1, 2}), 1.5);
}

TEST(ArrayServiceTest, MinAndMax)
{
    const Array<int> array{3, 1, 2};
    EXPECT_EQ(ArrayService::findMin(array), 1);
    EXPECT_EQ(ArrayService::findMax(array), 3);
}

TEST(ArrayServiceTest, IndexOfFirstMinAndMax)
{
    EXPECT_EQ(ArrayService::findIndexMax(Array<int>{3, 7, 7}), 1U);
    EXPECT_EQ(ArrayService::findIndexMin(Array<int>{2, 1, 1}), 1U);
}

TEST(ArrayServiceTest, EmptyArrayThrows)
{
    const Array<int> empty;
    EXPECT_THROW(static_cast<void>(ArrayService::average(empty)), std::invalid_argument);
    EXPECT_THROW(static_cast<void>(ArrayService::findMin(empty)), std::invalid_argument);
    EXPECT_THROW(static_cast<void>(ArrayService::findMax(empty)), std::invalid_argument);
    EXPECT_THROW(static_cast<void>(ArrayService::findIndexMin(empty)), std::invalid_argument);
    EXPECT_THROW(static_cast<void>(ArrayService::findIndexMax(empty)), std::invalid_argument);
}
