#include <sstream>
#include <stdexcept>
#include <string>

#include <gtest/gtest.h>

#include "complex_number.hpp"

namespace {

std::string toString(const ComplexNumber& number)
{
    std::ostringstream out;
    out << number;
    return out.str();
}

void expectComplex(const ComplexNumber& number, double re, double im)
{
    EXPECT_DOUBLE_EQ(number.getRe(), re);
    EXPECT_DOUBLE_EQ(number.getIm(), im);
}

} // namespace

TEST(ComplexNumberTest, Constructor)
{
    expectComplex(ComplexNumber(), 0.0, 0.0);
    expectComplex(ComplexNumber(1.5), 1.5, 0.0);
    expectComplex(ComplexNumber(1.0, -2.0), 1.0, -2.0);
}

TEST(ComplexNumberTest, ConjugateAndAbs)
{
    expectComplex(ComplexNumber(1.0, 2.0).conjugate(), 1.0, -2.0);
    EXPECT_DOUBLE_EQ(ComplexNumber(3.0, 4.0).abs(), 5.0);
}

TEST(ComplexNumberTest, Arithmetic)
{
    const ComplexNumber first{1.0, 2.0};
    const ComplexNumber second{3.0, -1.0};
    expectComplex(first + second, 4.0, 1.0);
    expectComplex(first - second, -2.0, 3.0);
    expectComplex(first * second, 5.0, 5.0);
    expectComplex(first / second, 0.1, 0.7);
    expectComplex(-first, -1.0, -2.0);
}

TEST(ComplexNumberTest, ImaginaryUnitSquared)
{
    const ComplexNumber i{0.0, 1.0};
    expectComplex(i * i, -1.0, 0.0);
}

TEST(ComplexNumberTest, DoubleOnEitherSide)
{
    const ComplexNumber number{1.0, 2.0};
    expectComplex(number + 1.0, 2.0, 2.0);
    expectComplex(1.0 + number, 2.0, 2.0);
    expectComplex(2.0 * number, 2.0, 4.0);
    expectComplex(1.0 - number, 0.0, -2.0);
}

TEST(ComplexNumberTest, DivisionByZeroThrows)
{
    EXPECT_THROW(ComplexNumber(1.0, 2.0) / 0.0, std::invalid_argument);
}

TEST(ComplexNumberTest, Equality)
{
    const ComplexNumber number{1.0, 0.0};
    EXPECT_TRUE(number == 1.0);
    EXPECT_TRUE(1.0 == number);
    EXPECT_FALSE(number != 1.0);
    EXPECT_FALSE(1.0 != number);
    EXPECT_TRUE(ComplexNumber(1.0, 2.0) != ComplexNumber(1.0, -2.0));
}

TEST(ComplexNumberTest, Output)
{
    EXPECT_EQ(toString(ComplexNumber(1.0, -2.0)), "(1, -2)");
    EXPECT_EQ(toString(ComplexNumber(0.5)), "(0.5, 0)");
}
