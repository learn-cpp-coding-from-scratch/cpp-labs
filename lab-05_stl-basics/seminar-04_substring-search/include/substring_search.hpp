#ifndef SUBSTRING_SEARCH_HPP
#define SUBSTRING_SEARCH_HPP

#include <string>
#include <utility>
#include <vector>

/// Для каждой пары строк из pairs — позиция (индекс с 0) первого вхождения второй строки в первую
/// или -1, если вторая строка не подстрока первой. Ответ YES или NO выводит main по этой позиции.
/// Пустая строка — подстрока любой строки, её позиция 0.
/// {{"banana", "ana"}, {"banana", "nab"}, {"abc", "c"}} → {1, -1, 2}.
std::vector<int> findSubstringPositions(const std::vector<std::pair<std::string, std::string>>& pairs);

#endif // SUBSTRING_SEARCH_HPP
