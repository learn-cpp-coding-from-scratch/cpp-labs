#ifndef DATA_IO_HPP
#define DATA_IO_HPP

#include <istream>
#include <ostream>
#include <vector>

// Шаблоны определены в src/data_io.cpp и созданы там явно для T = int и T = double.

/// Читает числа, разделённые пробелами и переводами строк, до конца потока или до первой ошибки чтения:
/// "3 -1\n2" → {3, -1, 2}.
template <typename T>
std::vector<T> readNumbers(std::istream& in);

/// Записывает числа через пробел и переводит строку: {3, -1, 2} → "3 -1 2\n".
template <typename T>
void writeNumbers(std::ostream& out, const std::vector<T>& numbers);

#endif // DATA_IO_HPP
