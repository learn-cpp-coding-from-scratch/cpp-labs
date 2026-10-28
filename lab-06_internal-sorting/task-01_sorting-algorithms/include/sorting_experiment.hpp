#ifndef SORTING_EXPERIMENT_HPP
#define SORTING_EXPERIMENT_HPP

#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

#include "sorting_algorithms.hpp"

/// Функция сортировки массива целых чисел, например &bubbleSort<int>.
using SortFunction = SortStatistics (*)(std::vector<int>& numbers);

/// Алгоритм эксперимента: имя функции ("bubbleSort") — для имён файлов,
/// название ("пузырьковая") — для сводной таблицы.
struct SortingAlgorithm {
    std::string name;
    std::string title;
    SortFunction sort = nullptr;
};

/// Результат одной сортировки: счётчики операций и время работы в миллисекундах.
struct Measurement {
    SortStatistics statistics;
    double milliseconds = 0.0;
};

/// Блок сводной таблицы: название и результаты measurements[номер размера][номер алгоритма].
struct ResultsBlock {
    std::string title;
    std::vector<std::vector<Measurement>> measurements;
};

/// Десять алгоритмов по порядку строк сводной таблицы:
/// вставкой, Шелла, пузырьковая, чет-нечет, шейкерная, расческой, выбором,
/// двусторонним выбором, быстрая, слиянием.
std::vector<SortingAlgorithm> sortingAlgorithms();

/// Сортирует numbers функцией sort и измеряет время её работы.
Measurement measureSort(SortFunction sort, std::vector<int>& numbers);

/// Среднее значение счётчиков (целая часть) и времени; для пустого списка — нули.
Measurement averageMeasurement(const std::vector<Measurement>& measurements);

/// Среднее по блокам одинакового размера: результат[i][j] — среднее blocks[k].measurements[i][j] по всем k.
/// Название блока — title.
ResultsBlock averageBlock(const std::string& title, const std::vector<ResultsBlock>& blocks);

/// Записывает сводную таблицу в формате CSV с разделителем ';' (открывается в Excel).
/// Для sizes = {10, 100}:
///   ";;n;10;;;100;;"  — размеры, каждый над своими тремя столбцами;
///   ";№;Параметр;Кол-во сравнений;Кол-во обменов;Время (ms);Кол-во сравнений;Кол-во обменов;Время (ms)";
///   затем строка на каждый алгоритм каждого блока: название блока (только в первой строке блока,
///   в остальных — пусто), номер алгоритма с 1, название алгоритма и для каждого размера —
///   сравнения, обмены и время с тремя знаками после точки:
///   "по возрастанию;1;вставкой;9;0;0.001;99;0;0.002", ";2;Шелла;…".
/// Каждая строка, включая последнюю, заканчивается переводом строки.
void writeResultsTable(std::ostream& out, const std::vector<std::size_t>& sizes,
                       const std::vector<SortingAlgorithm>& algorithms, const std::vector<ResultsBlock>& blocks);

#endif // SORTING_EXPERIMENT_HPP
