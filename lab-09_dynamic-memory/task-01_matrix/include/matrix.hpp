#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <initializer_list>
#include <istream>
#include <ostream>
// TODO: напишите решение

/// Прямоугольная матрица rows_ × columns_ из элементов типа T в динамической памяти.
/// data_ — массив из rows_ указателей на строки, каждая строка — массив из columns_ элементов.
/// Инвариант: у пустой матрицы rows_ == columns_ == 0 и data_ == nullptr; у непустой rows_ > 0 и columns_ > 0.
///
/// Шаблон класса целиком находится в заголовочном файле. Ниже класса — определения его
/// функций-членов; операции-друзья определены внутри класса.
template <typename T>
class Matrix
{
public:
    /// Пустая матрица 0×0.
    Matrix();

    /// Матрица rows × columns из элементов T{}. Нулевое число строк или столбцов — исключение
    /// std::invalid_argument.
    Matrix(std::size_t rows, std::size_t columns);

    /// Матрица rows × columns из элементов value. Нулевой размер — исключение std::invalid_argument.
    Matrix(std::size_t rows, std::size_t columns, const T& value);

    /// Матрица из списка строк: Matrix<int>{{1, 2}, {3, 4}}. Строки разной длины или пустые строки —
    /// исключение std::invalid_argument.
    Matrix(std::initializer_list<std::initializer_list<T>> rows);

    /// Именованные конструкторы — статические функции, создающие матрицу.
    /// Единичная матрица size × size: identity(2) — {{1, 0}, {0, 1}}. size == 0 — std::invalid_argument.
    static Matrix identity(std::size_t size);
    /// Диагональная матрица: diagonal({2, 3}) — {{2, 0}, {0, 3}}. Пустой список — std::invalid_argument.
    static Matrix diagonal(std::initializer_list<T> values);

    // Правило пяти
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    /// Присваивание копированием и перемещением — идиома копирования и обмена.
    Matrix& operator=(Matrix other) noexcept;
    ~Matrix();

    [[nodiscard]] std::size_t rows() const;
    [[nodiscard]] std::size_t columns() const;

    /// Элемент (row, column) без проверки индексов: m(0, 1) = 5.
    T& operator()(std::size_t row, std::size_t column);
    const T& operator()(std::size_t row, std::size_t column) const;

    /// Элемент с проверкой индексов: выход за границы — исключение std::out_of_range.
    T& at(std::size_t row, std::size_t column);
    [[nodiscard]] const T& at(std::size_t row, std::size_t column) const;

    /// Сложение и вычитание матриц; разные размеры — исключение std::invalid_argument.
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    /// Умножение и деление на значение типа T; деление на T{} — исключение std::domain_error.
    Matrix& operator*=(const T& value);
    Matrix& operator/=(const T& value);

    /// Противоположная матрица.
    Matrix operator-() const;

    /// Равны размеры и все элементы. Операцию != компилятор получает из ==.
    bool operator==(const Matrix& other) const;

    friend void swap(Matrix& lhs, Matrix& rhs) noexcept
    {
        // TODO: напишите решение
    }

    friend Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Matrix operator-(Matrix lhs, const Matrix& rhs)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Matrix operator*(Matrix lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Matrix operator*(const T& value, Matrix rhs)
    {
        // TODO: напишите решение
        return rhs;
    }

    friend Matrix operator/(Matrix lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    /// Произведение матриц: (m × n) * (n × k) — матрица m × k. Если число столбцов lhs не равно
    /// числу строк rhs — исключение std::invalid_argument.
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs)
    {
        // TODO: напишите решение
        return lhs;
    }

    /// Вывод: каждая строка матрицы — на отдельной строке, элементы через пробел: "1 2\n3 4\n".
    /// Пустая матрица ничего не выводит.
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
    {
        // TODO: напишите решение
        return out;
    }

    /// Ввод: число строк, число столбцов, затем элементы по строкам — "2 2 1 2 3 4".
    /// "0 0" — пустая матрица. При ошибке ввода (не число, отрицательный или только один нулевой
    /// размер, элементов не хватает) поток в состоянии ошибки (failbit), матрица не меняется.
    friend std::istream& operator>>(std::istream& in, Matrix& matrix)
    {
        // TODO: напишите решение
        return in;
    }

private:
    /// Выделяет rows строк по columns элементов T{}. Если выделение очередной строки не удалось,
    /// освобождает уже выделенные строки и передаёт исключение дальше.
    static T** allocate(std::size_t rows, std::size_t columns);

    /// Освобождает rows строк и массив указателей; data == nullptr допустим.
    static void release(T** data, std::size_t rows) noexcept;

    std::size_t rows_ = 0;
    std::size_t columns_ = 0;
    T** data_ = nullptr;
};

// ---------- Определения функций-членов ----------

template <typename T>
T** Matrix<T>::allocate(std::size_t rows, std::size_t columns)
{
    // TODO: напишите решение
    return nullptr;
}

template <typename T>
void Matrix<T>::release(T** data, std::size_t rows) noexcept
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T>::Matrix() = default;

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t columns)
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t columns, const T& value)
    // TODO: напишите решение
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> rows)
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T> Matrix<T>::identity(std::size_t size)
{
    // TODO: напишите решение
    return Matrix{};
}

template <typename T>
Matrix<T> Matrix<T>::diagonal(std::initializer_list<T> values)
{
    // TODO: напишите решение
    return Matrix{};
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept
{
    // TODO: напишите решение
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix other) noexcept
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Matrix<T>::~Matrix()
{
    // TODO: напишите решение
}

template <typename T>
std::size_t Matrix<T>::rows() const
{
    return rows_;
}

template <typename T>
std::size_t Matrix<T>::columns() const
{
    return columns_;
}

template <typename T>
T& Matrix<T>::operator()(std::size_t row, std::size_t column)
{
    return data_[row][column];
}

template <typename T>
const T& Matrix<T>::operator()(std::size_t row, std::size_t column) const
{
    return data_[row][column];
}

template <typename T>
T& Matrix<T>::at(std::size_t row, std::size_t column)
{
    // TODO: напишите решение
    return data_[row][column];
}

template <typename T>
const T& Matrix<T>::at(std::size_t row, std::size_t column) const
{
    // TODO: напишите решение
    return data_[row][column];
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator/=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& other) const
{
    // TODO: напишите решение
    return false;
}

#endif // MATRIX_HPP
