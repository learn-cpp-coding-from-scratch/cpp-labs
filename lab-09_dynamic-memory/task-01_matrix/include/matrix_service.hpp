#ifndef MATRIX_SERVICE_HPP
#define MATRIX_SERVICE_HPP

#include <cstddef>

#include "matrix.hpp"
// TODO: напишите решение

/// Функции обработки матриц — статические функции-члены.
/// Шаблоны (add … rotate) работают с любым Matrix<T> и определены в этом файле ниже класса;
/// determinant, inverse, solve — обычные функции для Matrix<double>, они определены
/// в src/matrix_service.cpp.
class MatrixService
{
public:
    /// Аналоги операций +, -, * класса Matrix (и те же исключения).
    template <typename T>
    static Matrix<T> add(const Matrix<T>& lhs, const Matrix<T>& rhs);
    template <typename T>
    static Matrix<T> subtract(const Matrix<T>& lhs, const Matrix<T>& rhs);
    /// Произведение матриц.
    template <typename T>
    static Matrix<T> multiply(const Matrix<T>& lhs, const Matrix<T>& rhs);
    /// Умножение на значение. Тип T выводится из обоих аргументов, поэтому для Matrix<double>
    /// пишите multiply(m, 2.0), а не multiply(m, 2).
    template <typename T>
    static Matrix<T> multiply(const Matrix<T>& matrix, const T& value);

    /// Транспонированная матрица: {{1, 2, 3}} — {{1}, {2}, {3}}. Пустая матрица — пустая.
    template <typename T>
    static Matrix<T> transpose(const Matrix<T>& matrix);

    /// Поворот на угол degrees, кратный 90 (90, 180, 270, -90, -180, -270, а также 0, 360 и т. д.).
    /// Положительный угол — против часовой стрелки: rotate({{1, 2}, {3, 4}}, 90) — {{2, 4}, {1, 3}},
    /// rotate({{1, 2}, {3, 4}}, -90) — {{3, 1}, {4, 2}}. Угол, не кратный 90, —
    /// исключение std::invalid_argument.
    template <typename T>
    static Matrix<T> rotate(const Matrix<T>& matrix, int degrees);

    /// Методом Гаусса с выбором главного элемента в столбце. Пустая или неквадратная матрица —
    /// исключение std::invalid_argument. Главный элемент, по модулю меньший 1e-9
    /// (cpplabs::DEFAULT_EPSILON), считается нулём.

    /// Определитель; у вырожденной матрицы — 0.
    static double determinant(const Matrix<double>& matrix);

    /// Обратная матрица; вырожденная матрица — исключение std::domain_error.
    static Matrix<double> inverse(const Matrix<double>& matrix);

    /// Решение матричного уравнения AX = B: a — n × n, b — n × k, результат X — n × k.
    /// Число строк b не равно n — исключение std::invalid_argument;
    /// вырожденная матрица a — исключение std::domain_error.
    static Matrix<double> solve(const Matrix<double>& a, const Matrix<double>& b);
};

// ---------- Определения шаблонов ----------

template <typename T>
Matrix<T> MatrixService::add(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    // TODO: напишите решение
    return lhs;
}

template <typename T>
Matrix<T> MatrixService::subtract(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    // TODO: напишите решение
    return lhs;
}

template <typename T>
Matrix<T> MatrixService::multiply(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    // TODO: напишите решение
    return lhs;
}

template <typename T>
Matrix<T> MatrixService::multiply(const Matrix<T>& matrix, const T& value)
{
    // TODO: напишите решение
    return matrix;
}

template <typename T>
Matrix<T> MatrixService::transpose(const Matrix<T>& matrix)
{
    // TODO: напишите решение
    return matrix;
}

template <typename T>
Matrix<T> MatrixService::rotate(const Matrix<T>& matrix, int degrees)
{
    // TODO: напишите решение
    return matrix;
}

#endif // MATRIX_SERVICE_HPP
