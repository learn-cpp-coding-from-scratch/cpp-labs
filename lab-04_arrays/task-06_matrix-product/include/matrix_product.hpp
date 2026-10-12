#ifndef MATRIX_PRODUCT_HPP
#define MATRIX_PRODUCT_HPP

#include <vector>

/// Произведение матриц left (n строк по k элементов) и right (k строк по m элементов) —
/// матрица из n строк по m элементов; элемент [i][j] равен сумме left[i][t] * right[t][j], t = 0..k-1.
/// Если в одной из матриц нет строк или длина строк left не равна числу строк right,
/// произведение не определено — результат пустой вектор.
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& left,
                                               const std::vector<std::vector<int>>& right);

#endif // MATRIX_PRODUCT_HPP
