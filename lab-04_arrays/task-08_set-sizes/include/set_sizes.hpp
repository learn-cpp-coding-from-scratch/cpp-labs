#ifndef SET_SIZES_HPP
#define SET_SIZES_HPP

#include <vector>

/// Количество элементов каждого набора. numbers — наборы, записанные подряд; каждый набор
/// завершается числом 0, которое в набор не входит: {5, -2, 0, 0, 7, 0} → {2, 0, 1}.
/// Числа после последнего 0 не образуют завершённого набора и не учитываются.
std::vector<int> countSetSizes(const std::vector<int>& numbers);

/// Общее количество элементов во всех наборах — сумма setSizes: {2, 0, 1} → 3.
int countAllElements(const std::vector<int>& setSizes);

#endif // SET_SIZES_HPP
