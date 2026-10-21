#ifndef PERIODIC_TASKS_HPP
#define PERIODIC_TASKS_HPP

#include <utility>
#include <vector>

/// count первых выполнений задач: пары {секунда, номер задачи}, номера задач — с 1.
/// periods[i] > 0 — период задачи с номером i + 1: она выполняется в секунды 0, periods[i], 2 * periods[i], …
/// Выполнения идут по возрастанию секунды, в одну секунду — по возрастанию номера задачи.
/// periods = {2, 3}, count = 6 → {{0, 1}, {0, 2}, {2, 1}, {3, 2}, {4, 1}, {6, 1}}.
std::vector<std::pair<int, int>> findFirstExecutions(const std::vector<int>& periods, int count);

#endif // PERIODIC_TASKS_HPP
