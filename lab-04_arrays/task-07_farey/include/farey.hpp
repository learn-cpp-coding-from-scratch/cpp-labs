#ifndef FAREY_HPP
#define FAREY_HPP

#include <utility>
#include <vector>

/// Несократимые дроби p/q, 0 < p/q < 1, со знаменателями q < n, в порядке возрастания;
/// дробь — пара (числитель p, знаменатель q).
/// n = 6 → 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5. Если n <= 2, таких дробей нет — пустой вектор.
std::vector<std::pair<int, int>> findFareyFractions(int n);

#endif // FAREY_HPP
