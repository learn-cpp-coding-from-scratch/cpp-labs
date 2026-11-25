#ifndef ARRAY_SERVICE_HPP
#define ARRAY_SERVICE_HPP

#include <cstddef>

#include "array.hpp"
// TODO: напишите решение

/// Функции обработки массива Array<T> — статические шаблоны функций-членов:
/// ArrayService::sum(a), тип T выводится из аргумента.
/// Для пустого массива average, findMin, findMax, findIndexMin, findIndexMax бросают
/// исключение std::invalid_argument.
class ArrayService
{
public:
    /// Сумма элементов: [1, 2, 3] — 6; у пустого массива — T{}.
    template <typename T>
    static T sum(const Array<T>& array);

    /// Среднее арифметическое: [1, 2] — 1.5.
    template <typename T>
    static double average(const Array<T>& array);

    /// Наименьший и наибольший элементы: [3, 1, 2] — 1 и 3.
    template <typename T>
    static T findMin(const Array<T>& array);
    template <typename T>
    static T findMax(const Array<T>& array);

    /// Индекс первого наименьшего (наибольшего) элемента: [3, 7, 7] — findIndexMax == 1.
    template <typename T>
    static std::size_t findIndexMin(const Array<T>& array);
    template <typename T>
    static std::size_t findIndexMax(const Array<T>& array);
};

// ---------- Определения ----------

template <typename T>
T ArrayService::sum(const Array<T>& array)
{
    T result{};
    // TODO: напишите решение
    return result;
}

template <typename T>
double ArrayService::average(const Array<T>& array)
{
    // TODO: напишите решение
    return 0.0;
}

template <typename T>
T ArrayService::findMin(const Array<T>& array)
{
    // TODO: напишите решение
    return T{};
}

template <typename T>
T ArrayService::findMax(const Array<T>& array)
{
    // TODO: напишите решение
    return T{};
}

template <typename T>
std::size_t ArrayService::findIndexMin(const Array<T>& array)
{
    std::size_t result = 0;
    // TODO: напишите решение
    return result;
}

template <typename T>
std::size_t ArrayService::findIndexMax(const Array<T>& array)
{
    std::size_t result = 0;
    // TODO: напишите решение
    return result;
}

#endif // ARRAY_SERVICE_HPP
