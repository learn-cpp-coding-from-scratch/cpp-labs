#ifndef TRANSPOSE_HPP
#define TRANSPOSE_HPP

#include <vector>

/// Транспонированная матрица: matrix — n строк по m элементов, результат — m строк по n элементов,
/// строка i результата — столбец i matrix: {{1, 2, 3}, {4, 5, 6}} → {{1, 4}, {2, 5}, {3, 6}}.
/// Если в matrix нет строк или строки пустые (n == 0 или m == 0), результат — пустой вектор.
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix);

#endif // TRANSPOSE_HPP
