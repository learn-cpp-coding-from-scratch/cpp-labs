#include "complex_number.hpp"

// TODO: напишите решение

ComplexNumber::ComplexNumber(double re, double im) : re_{re}, im_{im} {}

double ComplexNumber::getRe() const
{
    return re_;
}

double ComplexNumber::getIm() const
{
    return im_;
}

ComplexNumber ComplexNumber::conjugate() const
{
    // TODO: напишите решение
    return *this;
}

double ComplexNumber::abs() const
{
    // TODO: напишите решение
    return 0.0;
}

ComplexNumber ComplexNumber::operator-() const
{
    // TODO: напишите решение
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    // TODO: напишите решение
    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
    // TODO: напишите решение
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
    // TODO: напишите решение
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other)
{
    // TODO: напишите решение
    return *this;
}

ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

ComplexNumber operator-(ComplexNumber lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

ComplexNumber operator*(ComplexNumber lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

ComplexNumber operator/(ComplexNumber lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return lhs;
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& number)
{
    // TODO: напишите решение
    return out;
}
