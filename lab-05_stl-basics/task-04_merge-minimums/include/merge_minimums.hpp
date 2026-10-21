#ifndef MERGE_MINIMUMS_HPP
#define MERGE_MINIMUMS_HPP

#include <utility>
#include <vector>

/// numbers.size() - 1 раз два наименьших числа заменяются их суммой; после каждой замены
/// в результат добавляется пара {минимум, максимум} получившегося набора.
/// Для пустого набора и набора из одного числа результат пуст.
/// {4, 1, 3, 2} → {1, 2, 3, 4} → {3, 3, 4} → {4, 6} → {10}: результат {{3, 4}, {4, 6}, {10, 10}}.
std::vector<std::pair<int, int>> mergeMinimums(const std::vector<int>& numbers);

#endif // MERGE_MINIMUMS_HPP
