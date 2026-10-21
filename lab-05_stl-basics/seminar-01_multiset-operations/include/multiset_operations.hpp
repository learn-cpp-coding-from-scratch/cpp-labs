#ifndef MULTISET_OPERATIONS_HPP
#define MULTISET_OPERATIONS_HPP

#include <set>

// Число x входит в first n раз, в second — m раз. Тогда x входит:
// в объединение — max(n, m) раз, в пересечение — min(n, m) раз, в разность first / second — n - m раз
// (если n <= m, то ни разу). Пример: first = {1, 2, 2, 3}, second = {2, 3, 3, 4}.

/// Объединение first и second: {1, 2, 2, 3, 3, 4}.
std::multiset<int> uniteMultisets(const std::multiset<int>& first, const std::multiset<int>& second);

/// Пересечение first и second: {2, 3}.
std::multiset<int> intersectMultisets(const std::multiset<int>& first, const std::multiset<int>& second);

/// Разность first / second: {1, 2}; разность second / first: {3, 4}.
std::multiset<int> subtractMultisets(const std::multiset<int>& first, const std::multiset<int>& second);

#endif // MULTISET_OPERATIONS_HPP
