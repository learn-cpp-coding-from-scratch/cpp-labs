#include "complex_number.hpp"

ComplexNumber::ComplexNumber(double re, double im) : re_{re}, im_{im} {}

double ComplexNumber::getRe() const
{
    return re_;
}

double ComplexNumber::getIm() const
{
    return im_;
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return false;
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    // TODO: напишите решение
    return false;
}
