#ifndef MEANS_HPP
#define MEANS_HPP

#include <utility>
#include <vector>

/// first — среднее геометрическое положительных элементов numbers,
/// second — среднее арифметическое отрицательных элементов numbers.
/// Если положительных элементов нет, first равно 0; если нет отрицательных, second равно 0.
/// Значение 0 не путается с ответом: среднее геометрическое положительных чисел больше 0,
/// среднее арифметическое отрицательных чисел меньше 0.
std::pair<double, double> findMeans(const std::vector<double>& numbers);

#endif // MEANS_HPP
