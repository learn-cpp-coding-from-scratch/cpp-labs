#ifndef MULTISET_QUERIES_HPP
#define MULTISET_QUERIES_HPP

#include <set>
#include <string>
#include <vector>

/// Выполняет запросы queries над коллекцией numbers по порядку и возвращает строки выходного файла.
/// Запросы (по одному в строке, число — целое):
///   "add 7"      — добавить число 7;
///   "delete 7"   — удалить одно вхождение числа 7; если числа нет — ничего не делать;
///   "find_min"   — в результат строка с минимумом коллекции, для пустой коллекции — "EMPTY";
///   "is_exist 7" — в результат "YES", если 7 есть в коллекции, иначе "NO".
/// add и delete строк в результат не добавляют. Запросы записаны без ошибок.
/// numbers = {5, 3}, queries = {"find_min", "add 1", "is_exist 5", "delete 5", "is_exist 5", "find_min"}
/// → {"3", "YES", "NO", "1"}, numbers = {1, 3}.
/// Файлы читает и пишет main — примеры: data/numbers.txt, data/queries.txt.
std::vector<std::string> executeQueries(std::multiset<int>& numbers, const std::vector<std::string>& queries);

#endif // MULTISET_QUERIES_HPP
