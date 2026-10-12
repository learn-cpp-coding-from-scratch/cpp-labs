#ifndef ONE_TO_N_PERMUTATION_HPP
#define ONE_TO_N_PERMUTATION_HPP

#include <vector>

/// true, если numbers из n элементов содержит различные числа от 1 до n в любом порядке:
/// {3, 1, 2} → true, {1, 2, 2} → false, {1, 2, 4} → false.
/// Пустой массив (n = 0) — перестановка: чисел от 1 до 0 нет, и в массиве их нет.
bool isOneToNPermutation(const std::vector<int>& numbers);

#endif // ONE_TO_N_PERMUTATION_HPP
