#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <ostream>

/// Комплексное число re_ + im_·i.
class ComplexNumber
{
public:
    /// Число re + im·i. Без аргументов — 0, с одним — re + 0·i
    /// (неявное преобразование double в ComplexNumber: поэтому без explicit).
    ComplexNumber(double re = 0.0, double im = 0.0);

    [[nodiscard]] double getRe() const;
    [[nodiscard]] double getIm() const;

    /// Сопряжённое число: conjugate(1 + 2i) == 1 − 2i.
    [[nodiscard]] ComplexNumber conjugate() const;

    /// Модуль √(re² + im²): abs(3 + 4i) == 5.
    [[nodiscard]] double abs() const;

    /// Противоположное число: -(1 + 2i) == −1 − 2i.
    ComplexNumber operator-() const;

    /// Составные операции меняют число и возвращают ссылку на него.
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    /// Деление на 0 — исключение std::invalid_argument.
    ComplexNumber& operator/=(const ComplexNumber& other);

    /// Равенство по полям (C++20): из него компилятор получает !=,
    /// а 1.0 == z вычисляет как z == 1.0. Поля сравниваются точно, как значения double.
    bool operator==(const ComplexNumber& other) const = default;

private:
    double re_;
    double im_;
};

/// Бинарные операции — обычные функции, выраженные через составные: z + 1.0 и 1.0 + z работают оба.
/// Деление на 0 — исключение std::invalid_argument.
ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs);
ComplexNumber operator-(ComplexNumber lhs, const ComplexNumber& rhs);
ComplexNumber operator*(ComplexNumber lhs, const ComplexNumber& rhs);
ComplexNumber operator/(ComplexNumber lhs, const ComplexNumber& rhs);

/// Вывод в виде "(re, im)" с форматированием потока по умолчанию: (1, -2), (0.5, 0).
std::ostream& operator<<(std::ostream& out, const ComplexNumber& number);

#endif // COMPLEX_NUMBER_HPP
