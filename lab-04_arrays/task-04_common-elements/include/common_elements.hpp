#ifndef COMMON_ELEMENTS_HPP
#define COMMON_ELEMENTS_HPP

#include <vector>

/// Количество чисел, которые есть и в first, и в second.
/// first и second — возрастающие массивы: каждый следующий элемент больше предыдущего.
/// {1, 3, 5, 7}, {2, 3, 4, 7, 9} → 2 (общие элементы 3 и 7).
int countCommonElements(const std::vector<int>& first, const std::vector<int>& second);

#endif // COMMON_ELEMENTS_HPP
