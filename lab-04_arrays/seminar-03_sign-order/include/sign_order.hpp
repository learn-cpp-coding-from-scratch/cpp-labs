#ifndef SIGN_ORDER_HPP
#define SIGN_ORDER_HPP

#include <array>
#include <cstddef>

/// Количество элементов массива: размер std::array известен уже при компиляции
constexpr std::size_t ARRAY_SIZE = 10;

/// Переставляет элементы numbers: сначала отрицательные, затем нулевые, затем положительные.
/// Внутри каждой группы элементы стоят в прежнем порядке:
/// {3, -1, 0, -5, 2, 0, ...} → {-1, -5, ..., 0, 0, ..., 3, 2, ...}.
/// Вспомогательный массив не используется.
void arrangeBySign(std::array<int, ARRAY_SIZE>& numbers);

#endif // SIGN_ORDER_HPP
