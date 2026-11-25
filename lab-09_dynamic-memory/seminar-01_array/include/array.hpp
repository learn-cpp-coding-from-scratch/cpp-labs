#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <compare>
#include <cstddef>
#include <initializer_list>
#include <istream>
#include <ostream>
// TODO: напишите решение

/// Массив фиксированного размера из элементов типа T в динамической памяти.
/// Инвариант: data_ указывает на блок из size_ элементов; у пустого массива size_ == 0 и data_ == nullptr.
///
/// Шаблон класса целиком находится в заголовочном файле: компилятору нужно определение шаблона
/// в каждой единице трансляции, где создаётся Array<int>, Array<double> и т. д.
/// Ниже класса — определения его функций-членов; операции-друзья определены внутри класса.
template <typename T>
class Array
{
public:
    /// size элементов, равных T{}: Array<int>(3) — [0, 0, 0]. Без аргумента — пустой массив.
    explicit Array(std::size_t size = 0);

    /// size элементов, равных value: Array<int>(2, 7) — [7, 7].
    Array(std::size_t size, const T& value);

    /// Элементы из списка: Array<int>{1, 2, 3} — [1, 2, 3]. Внимание: Array<int>{3} — один элемент 3.
    Array(std::initializer_list<T> values);

    // Правило пяти
    /// Глубокое копирование: копия получает собственный блок памяти.
    Array(const Array& other);
    /// Забирает блок памяти other; other становится пустым.
    Array(Array&& other) noexcept;
    /// Присваивание копированием и перемещением — одна операция по идиоме копирования и обмена:
    /// параметр other передаётся по значению (создаётся копированием или перемещением аргумента)
    /// и обменивается с *this.
    Array& operator=(Array other) noexcept;
    ~Array();

    /// Присваивает value всем элементам: a = 5.
    Array& operator=(const T& value);

    [[nodiscard]] std::size_t size() const;

    /// Доступ к элементу без проверки индекса.
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    /// Доступ к элементу с проверкой: index >= size() — исключение std::out_of_range.
    T& at(std::size_t index);
    [[nodiscard]] const T& at(std::size_t index) const;

    /// Поэлементные сложение и вычитание массивов; разные размеры — исключение std::invalid_argument.
    Array& operator+=(const Array& other);
    Array& operator-=(const Array& other);

    /// Поэлементные операции со значением типа T: [1, 2] += 1 даёт [2, 3].
    Array& operator+=(const T& value);
    Array& operator-=(const T& value);
    Array& operator*=(const T& value);
    /// value == T{} — исключение std::domain_error.
    Array& operator/=(const T& value);

    /// Увеличение (уменьшение) каждого элемента на 1. Префиксные возвращают ссылку на массив,
    /// постфиксные — копию прежнего значения.
    Array& operator++();
    Array operator++(int);
    Array& operator--();
    Array operator--(int);

    /// Массивы равны, если равны размеры и все элементы. Операцию != компилятор получает из ==.
    bool operator==(const Array& other) const;

    /// Все элементы равны value: [7, 7] == 7. У пустого массива — true.
    bool operator==(const T& value) const;

    /// Обменивает содержимое двух массивов, не выбрасывает исключений.
    friend void swap(Array& lhs, Array& rhs) noexcept
    {
        // TODO: напишите решение
    }

    /// Бинарные операции выражены через составные. Они — скрытые друзья: обычные (не шаблонные)
    /// функции, которые создаются вместе с Array<T>, поэтому к их аргументам применяются
    /// неявные преобразования.
    friend Array operator+(Array lhs, const Array& rhs)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Array operator-(Array lhs, const Array& rhs)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Array operator+(Array lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Array operator+(const T& value, Array rhs)
    {
        // TODO: напишите решение
        return rhs;
    }

    friend Array operator-(Array lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Array operator*(Array lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    friend Array operator*(const T& value, Array rhs)
    {
        // TODO: напишите решение
        return rhs;
    }

    /// value == T{} — исключение std::domain_error.
    friend Array operator/(Array lhs, const T& value)
    {
        // TODO: напишите решение
        return lhs;
    }

    /// Лексикографическое сравнение: решает первый различающийся элемент (с меньшим индексом);
    /// если один массив — начало другого, меньше более короткий:
    /// [1, 2] < [1, 3], [1, 2] < [1, 2, 0], [2] > [1, 9].
    /// Тип результата — как у сравнения элементов: для int — std::strong_ordering,
    /// для double — std::partial_ordering. Из <=> компилятор получает <, >, <=, >=.
    friend auto operator<=>(const Array& lhs, const Array& rhs)
    {
        // TODO: напишите решение
        return lhs.size_ <=> rhs.size_;
    }

    /// Вывод элементов через запятую с пробелом в квадратных скобках: [1, 2, 3]; пустой массив — [].
    friend std::ostream& operator<<(std::ostream& out, const Array& array)
    {
        // TODO: напишите решение
        return out;
    }

    /// Ввод: размер, затем элементы — "3 1 2 3". При ошибке ввода (не число, отрицательный размер,
    /// элементов меньше, чем размер) поток в состоянии ошибки (failbit), массив не меняется.
    friend std::istream& operator>>(std::istream& in, Array& array)
    {
        // TODO: напишите решение
        return in;
    }

private:
    std::size_t size_ = 0;
    T* data_ = nullptr;
};

// ---------- Определения функций-членов ----------

template <typename T>
Array<T>::Array(std::size_t size)
    // TODO: напишите решение
{
}

template <typename T>
Array<T>::Array(std::size_t size, const T& value)
    // TODO: напишите решение
{
    // TODO: напишите решение
}

template <typename T>
Array<T>::Array(std::initializer_list<T> values)
    // TODO: напишите решение
{
    // TODO: напишите решение
}

template <typename T>
Array<T>::Array(const Array& other)
    // TODO: напишите решение
{
    // TODO: напишите решение
}

template <typename T>
Array<T>::Array(Array&& other) noexcept
    // TODO: напишите решение
{
    // TODO: напишите решение
}

template <typename T>
Array<T>& Array<T>::operator=(Array other) noexcept
{
    // TODO: напишите решение
    return *this;
} // старый блок *this освобождает деструктор other

template <typename T>
Array<T>::~Array()
{
    // TODO: напишите решение
}

template <typename T>
Array<T>& Array<T>::operator=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
std::size_t Array<T>::size() const
{
    return size_;
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
    return data_[index];
}

template <typename T>
T& Array<T>::at(std::size_t index)
{
    // TODO: напишите решение
    return data_[index];
}

template <typename T>
const T& Array<T>::at(std::size_t index) const
{
    // TODO: напишите решение
    return data_[index];
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& other)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const Array& other)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator+=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator*=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator/=(const T& value)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator++()
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T> Array<T>::operator++(int)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator--()
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
Array<T> Array<T>::operator--(int)
{
    // TODO: напишите решение
    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array& other) const
{
    // TODO: напишите решение
    return false;
}

template <typename T>
bool Array<T>::operator==(const T& value) const
{
    // TODO: напишите решение
    return false;
}

#endif // ARRAY_HPP
