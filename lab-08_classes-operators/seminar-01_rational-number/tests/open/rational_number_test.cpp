#include <sstream>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

#include "rational_number.hpp"

namespace {

std::string toString(const RationalNumber& number)
{
    std::ostringstream out;
    out << number;
    return out.str();
}

} // namespace

// 1. Инвариант и конструктор

TEST(RationalNumberTest, DefaultIsZero)
{
    const RationalNumber number;
    EXPECT_EQ(number.getNumerator(), 0);
    EXPECT_EQ(number.getDenominator(), 1);
}

TEST(RationalNumberTest, ConstructorReduces)
{
    const RationalNumber number{2, 4};
    EXPECT_EQ(number.getNumerator(), 1);
    EXPECT_EQ(number.getDenominator(), 2);
}

TEST(RationalNumberTest, ConstructorMovesSignToNumerator)
{
    const RationalNumber number{1, -2};
    EXPECT_EQ(number.getNumerator(), -1);
    EXPECT_EQ(number.getDenominator(), 2);
}

TEST(RationalNumberTest, ZeroNumerator)
{
    const RationalNumber number{0, 5};
    EXPECT_EQ(number.getNumerator(), 0);
    EXPECT_EQ(number.getDenominator(), 1);
}

TEST(RationalNumberTest, ZeroDenominatorThrows)
{
    EXPECT_THROW(RationalNumber(1, 0), std::invalid_argument);
}

// 2. Арифметические операции

TEST(RationalNumberTest, Addition)
{
    EXPECT_EQ(RationalNumber(1, 6) + RationalNumber(1, 3), RationalNumber(1, 2));
}

TEST(RationalNumberTest, Subtraction)
{
    EXPECT_EQ(RationalNumber(1, 2) - RationalNumber(1, 2), RationalNumber(0));
}

TEST(RationalNumberTest, Multiplication)
{
    EXPECT_EQ(RationalNumber(2, 3) * RationalNumber(3, 4), RationalNumber(1, 2));
}

TEST(RationalNumberTest, Division)
{
    EXPECT_EQ(RationalNumber(1, 2) / RationalNumber(1, 4), RationalNumber(2));
}

TEST(RationalNumberTest, UnaryMinus)
{
    EXPECT_EQ(-RationalNumber(1, 2), RationalNumber(-1, 2));
}

TEST(RationalNumberTest, IntegerOnEitherSide)
{
    EXPECT_EQ(1 + RationalNumber(1, 2), RationalNumber(3, 2));
    EXPECT_EQ(RationalNumber(1, 2) + 1, RationalNumber(3, 2));
}

TEST(RationalNumberTest, CompoundAssignmentReturnsSelf)
{
    RationalNumber number{1, 2};
    (number += RationalNumber(1, 2)) *= 3;
    EXPECT_EQ(number, RationalNumber(3));
}

TEST(RationalNumberTest, DivisionByZeroThrows)
{
    EXPECT_THROW(RationalNumber(1, 2) / 0, std::domain_error);
}

// 3. Сравнение

TEST(RationalNumberTest, EqualityWithInteger)
{
    EXPECT_EQ(RationalNumber(4, 2), 2);
    EXPECT_NE(RationalNumber(1, 2), RationalNumber(1, 3));
}

TEST(RationalNumberTest, OrderByValue)
{
    EXPECT_LT(RationalNumber(1, 3), RationalNumber(1, 2));
    EXPECT_LT(RationalNumber(-1, 2), RationalNumber(1, 3));
    EXPECT_GT(2, RationalNumber(3, 2));
}

// 4. Вывод

TEST(RationalNumberTest, Output)
{
    EXPECT_EQ(toString(RationalNumber(6, 4)), "3/2");
    EXPECT_EQ(toString(RationalNumber(-1, 2)), "-1/2");
    EXPECT_EQ(toString(RationalNumber(3, 1)), "3");
}

// 5. Правило нуля

TEST(RationalNumberTest, CopyAndAssignInteger)
{
    const RationalNumber first{1, 2};
    RationalNumber second = first;
    EXPECT_EQ(second, first);
    second = 5;
    EXPECT_EQ(second, RationalNumber(5));
}
