#include "rational_number.hpp"

// TODO: напишите решение

RationalNumber::RationalNumber(int numerator, int denominator)
    : numerator_{numerator}, denominator_{denominator}
{
    // TODO: напишите решение
}

int RationalNumber::getNumerator() const
{
    return numerator_;
}

int RationalNumber::getDenominator() const
{
    return denominator_;
}

double RationalNumber::toDouble() const
{
    // TODO: напишите решение
    return 0.0;
}

RationalNumber RationalNumber::operator-() const
{
    // TODO: напишите решение
    return *this;
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& other)
{
    // TODO: напишите решение
    return *this;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& other)
{
    // TODO: напишите решение
    return *this;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& other)
{
    // TODO: напишите решение
    return *this;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& other)
{
    // TODO: напишите решение
    return *this;
}

void RationalNumber::normalize()
{
    // TODO: напишите решение
}

RationalNumber operator+(RationalNumber lhs, const RationalNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

RationalNumber operator-(RationalNumber lhs, const RationalNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

RationalNumber operator*(RationalNumber lhs, const RationalNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

RationalNumber operator/(RationalNumber lhs, const RationalNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

std::strong_ordering operator<=>(const RationalNumber& lhs, const RationalNumber& rhs)
{
    // TODO: напишите решение
    return std::strong_ordering::equal;
}

std::ostream& operator<<(std::ostream& out, const RationalNumber& number)
{
    // TODO: напишите решение
    return out;
}

RationalNumber power(const RationalNumber& number, int exponent)
{
    // TODO: напишите решение
    return number;
}

RationalNumber abs(const RationalNumber& number)
{
    // TODO: напишите решение
    return number;
}
