#ifndef REMOVE_ZEROS_HPP
#define REMOVE_ZEROS_HPP

#include <vector>

/// Удаляет из numbers нулевые элементы; остальные элементы сохраняют взаимный порядок,
/// размер numbers уменьшается на число удалённых нулей: {0, 5, 0, 0, -3, 7} → {5, -3, 7}.
void removeZeros(std::vector<int>& numbers);

#endif // REMOVE_ZEROS_HPP
