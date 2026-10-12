#ifndef SWAP_PARTS_HPP
#define SWAP_PARTS_HPP

#include <cstddef>
#include <vector>

/// Меняет местами начало numbers длины beginLength (n) и конец длины m = numbers.size() - n;
/// порядок элементов внутри частей сохраняется: {1, 2, 3, 4, 5, 6}, n = 2 → {3, 4, 5, 6, 1, 2}.
/// Вспомогательные массивы не используются. Если beginLength > numbers.size(), numbers не меняется.
void swapParts(std::vector<int>& numbers, std::size_t beginLength);

#endif // SWAP_PARTS_HPP
