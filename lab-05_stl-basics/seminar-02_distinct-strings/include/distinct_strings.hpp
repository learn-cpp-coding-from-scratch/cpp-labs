#ifndef DISTINCT_STRINGS_HPP
#define DISTINCT_STRINGS_HPP

#include <string>
#include <vector>

/// Количество различных строк среди lines: {"abc", "ab", "abc", "x"} → 3.
/// Строки файла читает main (по одной в элемент вектора) — пример файла: data/strings.txt.
int countDistinctStrings(const std::vector<std::string>& lines);

#endif // DISTINCT_STRINGS_HPP
