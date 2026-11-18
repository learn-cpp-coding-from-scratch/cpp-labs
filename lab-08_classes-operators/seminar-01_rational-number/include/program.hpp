#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <istream>
#include <ostream>
#include <string>

#include "rational_number.hpp"

/// Демонстрация работы с рациональными числами: ввод двух дробей, арифметика и сравнения.
class Program
{
public:
    /// Работа программы с клавиатурой и консолью: return run(std::cin, std::cout);
    /// вызывается из функции main. Код возврата — 0, при ошибке ввода — 1.
    int main();

    /// Вводит из in две дроби (числитель и знаменатель через пробел) и выводит в out:
    ///   a = 1/2
    ///   b = 1/3
    ///   a + b = 5/6
    ///   a - b = 1/6
    ///   a * b = 1/6
    ///   a / b = 3/2
    ///   a == b: false
    ///   a != b: true
    ///   a < b: false
    ///   a > b: true
    ///   a <= b: false
    ///   a >= b: true
    /// Перед вводом дроби — приглашение "Enter fraction a (numerator denominator): ".
    /// При нулевом знаменателе — строка "Error: <сообщение исключения>" и повторный ввод этой
    /// дроби. При делении на ноль вместо частного — "a / b = Error: <сообщение исключения>". Если
    /// ввод не удался (не число, конец ввода) — строка "Error: input error", работа заканчивается.
    /// Возвращает 0, при ошибке ввода — 1.
    int run(std::istream& in, std::ostream& out);

private:
    /// Вводит дробь с именем name, повторяя ввод при нулевом знаменателе.
    /// Ошибка ввода — исключение std::runtime_error("input error").
    RationalNumber readRationalNumber(std::istream& in, std::ostream& out, const std::string& name);

    /// Выводит first_ и second_, результаты +, -, *, /.
    void printArithmetic(std::ostream& out) const;

    /// Выводит результаты ==, !=, <, >, <=, >=.
    void printComparisons(std::ostream& out) const;

    RationalNumber first_;
    RationalNumber second_;
};

#endif // PROGRAM_HPP
