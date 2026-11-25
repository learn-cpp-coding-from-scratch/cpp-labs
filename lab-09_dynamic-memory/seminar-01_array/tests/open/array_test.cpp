#include <compare>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include <gtest/gtest.h>

#include "array.hpp"

namespace {

template <typename T>
std::string toString(const Array<T>& array)
{
    std::ostringstream out;
    out << array;
    return out.str();
}

} // namespace

// 1. Поля и правило пяти

TEST(ArrayTest, DefaultIsEmpty)
{
    const Array<int> array;
    EXPECT_EQ(array.size(), 0U);
    EXPECT_EQ(toString(array), "[]");
}

TEST(ArrayTest, SizeConstructorFillsWithZeros)
{
    const Array<int> array(3);
    EXPECT_EQ(toString(array), "[0, 0, 0]");
}

TEST(ArrayTest, SizeValueConstructor)
{
    const Array<int> array(2, 7);
    EXPECT_EQ(toString(array), "[7, 7]");
}

TEST(ArrayTest, InitializerList)
{
    const Array<int> array{1, 2, 3};
    EXPECT_EQ(array.size(), 3U);
    EXPECT_EQ(toString(array), "[1, 2, 3]");
}

TEST(ArrayTest, BracesWithOneNumberMakeOneElement)
{
    const Array<int> array{3};
    EXPECT_EQ(toString(array), "[3]");
}

TEST(ArrayTest, SizeConstructorIsExplicit)
{
    EXPECT_FALSE((std::is_convertible_v<std::size_t, Array<int>>));
}

TEST(ArrayTest, CopyIsDeep)
{
    const Array<int> original{1, 2};
    Array<int> copy = original;
    copy[0] = 9;
    EXPECT_EQ(toString(original), "[1, 2]");
    EXPECT_EQ(toString(copy), "[9, 2]");
}

TEST(ArrayTest, CopyAssignmentIsDeep)
{
    const Array<int> original{1, 2};
    Array<int> copy{5};
    copy = original;
    copy[1] = 9;
    EXPECT_EQ(toString(original), "[1, 2]");
    EXPECT_EQ(toString(copy), "[1, 9]");
}

TEST(ArrayTest, SelfAssignment)
{
    Array<int> array{1, 2};
    const Array<int>& alias = array;
    array = alias;
    EXPECT_EQ(toString(array), "[1, 2]");
}

TEST(ArrayTest, MoveConstructorEmptiesSource)
{
    Array<int> source{1, 2};
    const Array<int> target = std::move(source);
    EXPECT_EQ(toString(target), "[1, 2]");
    EXPECT_EQ(source.size(), 0U); // NOLINT(bugprone-use-after-move): проверяем состояние после перемещения
}

TEST(ArrayTest, MoveAssignmentEmptiesSource)
{
    Array<int> source{1, 2};
    Array<int> target{7, 8, 9};
    target = std::move(source);
    EXPECT_EQ(toString(target), "[1, 2]");
    EXPECT_EQ(source.size(), 0U); // NOLINT(bugprone-use-after-move)
}

TEST(ArrayTest, MoveOperationsAreNoexcept)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible_v<Array<int>>);
    EXPECT_TRUE(std::is_nothrow_move_assignable_v<Array<int>>);
}

TEST(ArrayTest, Swap)
{
    Array<int> first{1};
    Array<int> second{2, 3};
    swap(first, second);
    EXPECT_EQ(toString(first), "[2, 3]");
    EXPECT_EQ(toString(second), "[1]");
}

// 2. Доступ к элементам

TEST(ArrayTest, IndexOperator)
{
    Array<int> array(2);
    array[1] = 5;
    const Array<int>& view = array;
    EXPECT_EQ(view[1], 5);
}

TEST(ArrayTest, AtChecksIndex)
{
    Array<int> array{1, 2};
    array.at(1) = 4;
    EXPECT_EQ(array.at(1), 4);
    EXPECT_THROW(static_cast<void>(array.at(2)), std::out_of_range);
    const Array<int>& view = array;
    EXPECT_THROW(static_cast<void>(view.at(2)), std::out_of_range);
}

// 3. Операции

TEST(ArrayTest, AssignValueToAllElements)
{
    Array<int> array(3);
    array = 5;
    EXPECT_EQ(toString(array), "[5, 5, 5]");
}

TEST(ArrayTest, AddArrays)
{
    EXPECT_EQ(toString(Array<int>{1, 2} + Array<int>{3, 4}), "[4, 6]");
    Array<int> array{1, 2};
    array += Array<int>{3, 4};
    EXPECT_EQ(toString(array), "[4, 6]");
}

TEST(ArrayTest, SubtractArrays)
{
    EXPECT_EQ(toString(Array<int>{5, 5} - Array<int>{1, 2}), "[4, 3]");
}

TEST(ArrayTest, DifferentSizesThrow)
{
    EXPECT_THROW(Array<int>({1, 2}) + Array<int>{1}, std::invalid_argument);
    EXPECT_THROW(Array<int>({1, 2}) - Array<int>{1}, std::invalid_argument);
}

TEST(ArrayTest, OperationsWithValue)
{
    EXPECT_EQ(toString(Array<int>{1, 2} + 1), "[2, 3]");
    EXPECT_EQ(toString(1 + Array<int>{1, 2}), "[2, 3]");
    EXPECT_EQ(toString(Array<int>{1, 2} - 1), "[0, 1]");
    EXPECT_EQ(toString(Array<int>{1, 2} * 2), "[2, 4]");
    EXPECT_EQ(toString(2 * Array<int>{1, 2}), "[2, 4]");
    EXPECT_EQ(toString(Array<int>{4, 6} / 2), "[2, 3]");
}

TEST(ArrayTest, CompoundOperationsWithValue)
{
    Array<int> array{2, 4};
    array += 2;
    EXPECT_EQ(toString(array), "[4, 6]");
    array -= 1;
    EXPECT_EQ(toString(array), "[3, 5]");
    array *= 2;
    EXPECT_EQ(toString(array), "[6, 10]");
    array /= 2;
    EXPECT_EQ(toString(array), "[3, 5]");
}

TEST(ArrayTest, DivisionByZeroThrows)
{
    EXPECT_THROW(Array<int>({1, 2}) / 0, std::domain_error);
    Array<double> array{1.0};
    EXPECT_THROW(array /= 0.0, std::domain_error);
}

TEST(ArrayTest, IncrementAndDecrement)
{
    Array<int> array{1, 2};
    EXPECT_EQ(toString(++array), "[2, 3]");
    EXPECT_EQ(toString(array++), "[2, 3]");
    EXPECT_EQ(toString(array), "[3, 4]");
    EXPECT_EQ(toString(--array), "[2, 3]");
    EXPECT_EQ(toString(array--), "[2, 3]");
    EXPECT_EQ(toString(array), "[1, 2]");
}

TEST(ArrayTest, Equality)
{
    EXPECT_TRUE((Array<int>{1, 2} == Array<int>{1, 2}));
    EXPECT_FALSE((Array<int>{1, 2} == Array<int>{1, 3}));
    EXPECT_FALSE((Array<int>{1, 2} == Array<int>{1, 2, 0}));
    EXPECT_TRUE((Array<int>{1, 2} != Array<int>{2, 1}));
}

TEST(ArrayTest, EqualityWithValue)
{
    EXPECT_TRUE((Array<int>{7, 7} == 7));
    EXPECT_FALSE((Array<int>{7, 8} == 7));
    EXPECT_TRUE((Array<int>{7, 8} != 7));
    EXPECT_TRUE((Array<int>{} == 7));
}

TEST(ArrayTest, LexicographicalComparison)
{
    EXPECT_TRUE((Array<int>{1, 2} < Array<int>{1, 3}));
    EXPECT_TRUE((Array<int>{1, 2} < Array<int>{1, 2, 0}));
    EXPECT_TRUE((Array<int>{2} > Array<int>{1, 9}));
    EXPECT_TRUE((Array<int>{1, 2} <= Array<int>{1, 2}));
    EXPECT_TRUE((Array<int>{1, 2} >= Array<int>{1, 2}));
    EXPECT_FALSE((Array<int>{} > Array<int>{}));
}

TEST(ArrayTest, ComparisonCategoryFollowsElements)
{
    EXPECT_TRUE((std::is_same_v<decltype(Array<int>{} <=> Array<int>{}), std::strong_ordering>));
    EXPECT_TRUE((std::is_same_v<decltype(Array<double>{} <=> Array<double>{}), std::partial_ordering>));
}

// 4. Ввод и вывод

TEST(ArrayTest, OutputDouble)
{
    EXPECT_EQ(toString(Array<double>{0.5, 1.5}), "[0.5, 1.5]");
}

TEST(ArrayTest, Input)
{
    std::istringstream in{"3 1 2 3"};
    Array<int> array;
    in >> array;
    EXPECT_FALSE(in.fail());
    EXPECT_EQ(toString(array), "[1, 2, 3]");
}

TEST(ArrayTest, InputErrorKeepsArray)
{
    std::istringstream in{"3 1 x 3"};
    Array<int> array{9};
    in >> array;
    EXPECT_TRUE(in.fail());
    EXPECT_EQ(toString(array), "[9]");
}
