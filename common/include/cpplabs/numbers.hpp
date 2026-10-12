#ifndef CPPLABS_NUMBERS_HPP
#define CPPLABS_NUMBERS_HPP

namespace cpplabs {

// допуск по умолчанию для приближённого сравнения дробных чисел
constexpr double DEFAULT_EPSILON = 1e-9;

// приближённое равенство дробных чисел: |a - b| < epsilon
bool isNearlyEqual(double a, double b, double epsilon = DEFAULT_EPSILON);

} // namespace cpplabs

#endif // CPPLABS_NUMBERS_HPP
