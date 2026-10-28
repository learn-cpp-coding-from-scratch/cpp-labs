#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <cstdint>
#include <vector>

/// Счётчики операций одной сортировки.
/// comparisons — сравнения двух элементов массива (или элемента с сохранённым значением, например с опорным);
/// swaps — обмены и перемещения: обмен двух элементов — одна операция, запись элемента
/// на новое место (сдвиг в сортировке вставками, копирование при слиянии) — тоже одна.
struct SortStatistics {
    std::int64_t comparisons = 0;
    std::int64_t swaps = 0;
};

// Все функции упорядочивают numbers по неубыванию: {3, -1, 2, -1} → {-1, -1, 2, 3}
// и возвращают счётчики операций. Шаблоны определены в src/sorting_algorithms.cpp
// и созданы там явно для T = int и T = double.

/// Сортировка вставками.
template <typename T>
SortStatistics insertionSort(std::vector<T>& numbers);

/// Сортировка Шелла: сортировка вставками элементов, стоящих на расстоянии gap, gap уменьшается до 1.
template <typename T>
SortStatistics shellSort(std::vector<T>& numbers);

/// Сортировка пузырьком; заканчивается, когда за проход не было обменов.
template <typename T>
SortStatistics bubbleSort(std::vector<T>& numbers);

/// Чётно-нечётная сортировка: проходы по парам (0, 1), (2, 3), … и (1, 2), (3, 4), … чередуются,
/// пока за два прохода подряд не было обменов.
template <typename T>
SortStatistics oddEvenSort(std::vector<T>& numbers);

/// Шейкерная сортировка: пузырьковая с чередованием направлений просмотра.
template <typename T>
SortStatistics cocktailSort(std::vector<T>& numbers);

/// Сортировка расчёской: пузырьковая с расстоянием между сравниваемыми элементами,
/// которое уменьшается до 1.
template <typename T>
SortStatistics combSort(std::vector<T>& numbers);

/// Сортировка выбором.
template <typename T>
SortStatistics selectionSort(std::vector<T>& numbers);

/// Двусторонняя сортировка выбором: за проход минимум ставится в начало, максимум — в конец
/// неотсортированной части.
template <typename T>
SortStatistics doubleSelectionSort(std::vector<T>& numbers);

/// Быстрая сортировка.
template <typename T>
SortStatistics quickSort(std::vector<T>& numbers);

/// Сортировка слиянием.
template <typename T>
SortStatistics mergeSort(std::vector<T>& numbers);

#endif // SORTING_ALGORITHMS_HPP
