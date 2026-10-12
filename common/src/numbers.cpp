#include <cpplabs/numbers.hpp>

#include <cmath>

namespace cpplabs {

bool isNearlyEqual(double a, double b, double epsilon)
{
    return std::fabs(a - b) < epsilon;
}

} // namespace cpplabs
