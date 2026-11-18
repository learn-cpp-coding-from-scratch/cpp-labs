#ifndef RATIONAL_NUMBER_HPP
#define RATIONAL_NUMBER_HPP

#include <compare>
#include <ostream>

/// Рациональное число — дробь numerator_/denominator_.
/// Инвариант: denominator_ > 0, дробь несократима (0 хранится как 0/1).
class RationalNumber
{
public:
    /// Дробь numerator/denominator, приведённая к несократимому виду со знаменателем больше нуля:
    /// {2, 4} → 1/2, {1, -2} → -1/2, {0, 5} → 0/1. Без аргументов — 0/1, с одним — numerator/1
    /// (неявное преобразование целого числа в дробь). Знаменатель 0 — исключение
    /// std::invalid_argument.
    RationalNumber(int numerator = 0, int denominator = 1);

    [[nodiscard]] int getNumerator() const;
    [[nodiscard]] int getDenominator() const;

    /// Дополнительно (по желанию). Значение дроби типа double: 1/4 → 0.25.
    [[nodiscard]] double toDouble() const;

    /// Противоположная дробь: -(1/2) == -1/2.
    RationalNumber operator-() const;

    /// Составные операции меняют дробь, восстанавливают инвариант и возвращают ссылку на неё.
    RationalNumber& operator+=(const RationalNumber& other);
    RationalNumber& operator-=(const RationalNumber& other);
    RationalNumber& operator*=(const RationalNumber& other);
    /// Деление на нулевую дробь — исключение std::domain_error.
    RationalNumber& operator/=(const RationalNumber& other);

    /// Равенство по полям: верно благодаря инварианту —
    /// равные дроби хранятся одинаково (2/4 как 1/2).
    bool operator==(const RationalNumber& other) const = default;

private:
    /// Восстанавливает инвариант: знак — в числитель, сокращение на НОД.
    void normalize();

    int numerator_;
    int denominator_;
};

/// Бинарные операции — обычные функции, выраженные через составные: 1 + r и r + 1 работают оба
/// (int неявно преобразуется в RationalNumber). Деление на нулевую дробь — исключение
/// std::domain_error.
RationalNumber operator+(RationalNumber lhs, const RationalNumber& rhs);
RationalNumber operator-(RationalNumber lhs, const RationalNumber& rhs);
RationalNumber operator*(RationalNumber lhs, const RationalNumber& rhs);
RationalNumber operator/(RationalNumber lhs, const RationalNumber& rhs);

/// Сравнение по величине: a/b <=> c/d равносильно a*d <=> c*b (знаменатели положительны);
/// произведения вычисляются в long long. Из <=> компилятор получает <, >, <=, >=.
std::strong_ordering operator<=>(const RationalNumber& lhs, const RationalNumber& rhs);

/// Вывод "числитель/знаменатель"; при знаменателе 1 — только числитель: 3/2, -1/2, 3.
std::ostream& operator<<(std::ostream& out, const RationalNumber& number);

/// Дополнительно (по желанию). Целая степень дроби, в том числе отрицательная:
/// power(2/3, 2) == 4/9, power(2/3, -2) == 9/4, power(r, 0) == 1.
/// Ноль в отрицательной степени — исключение std::domain_error.
RationalNumber power(const RationalNumber& number, int exponent);

/// Дополнительно (по желанию). Модуль дроби: abs(-1/2) == 1/2.
RationalNumber abs(const RationalNumber& number);

#endif // RATIONAL_NUMBER_HPP
