#ifndef PERMUTATION_OF_ARRAY_HPP
#define PERMUTATION_OF_ARRAY_HPP

#include <vector>

/// true, если first — перестановка элементов second: в first те же элементы, что в second,
/// и каждый встречается столько же раз, порядок может быть другим.
/// {3, 1, 2, 1} — перестановка {1, 1, 2, 3}; {1, 2, 2} — не перестановка {1, 1, 2}.
bool isPermutationOf(const std::vector<int>& first, const std::vector<int>& second);

#endif // PERMUTATION_OF_ARRAY_HPP
