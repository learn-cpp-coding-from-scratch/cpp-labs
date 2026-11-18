#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <istream>
#include <ostream>
#include <string>

#include "complex_number.hpp"

/// Демонстрация работы с комплексными числами: меню, арифметика, множество Мандельброта.
class Program
{
public:
    /// Работа программы с клавиатурой и консолью: return run(std::cin, std::cout);
    /// вызывается из функции main. Код возврата — 0, при ошибке ввода — 1.
    int main();

    /// Выводит меню и выполняет выбранный пункт, пока не выбран выход или не кончился ввод:
    ///   "Menu: 1 - arithmetic, 2 - Mandelbrot set, 0 - exit\nChoice: "
    /// 1 — printArithmetic, 2 — printMandelbrot, 0 — выход;
    /// другое число — строка "Unknown choice: <число>", затем снова меню.
    /// Если ввод не удался (не число, конец ввода) — работа заканчивается.
    /// Исключение при выполнении пункта (например, неверные параметры множества) —
    /// строка "Error: <сообщение исключения>", затем снова меню. Ошибка ввода внутри пункта —
    /// строка "Error: input error", работа заканчивается.
    /// Возвращает 0 (выход или конец ввода в меню), при ошибке ввода внутри пункта — 1.
    int run(std::istream& in, std::ostream& out);

private:
    /// Вводит действительную и мнимую части числа с именем name после приглашения
    /// "Enter <name> (re im): ". Ошибка ввода — исключение std::runtime_error("input error").
    ComplexNumber readComplexNumber(std::istream& in, std::ostream& out, const std::string& name);

    /// Вводит z1 и z2 и выводит:
    ///   z1 = (1, 2)
    ///   z2 = (3, -1)
    ///   z1 + z2 = (4, 1)
    ///   z1 - z2 = (-2, 3)
    ///   z1 * z2 = (5, 5)
    ///   z1 / z2 = (0.1, 0.7)
    ///   conj(z1) = (1, -2)
    ///   |z1| = 2.23607
    ///   |z2| = 3.16228
    ///   z1 == z2: false
    /// При делении на 0 вместо частного — "z1 / z2 = Error: <сообщение исключения>".
    void printArithmetic(std::istream& in, std::ostream& out);

    /// Вводит границы после приглашения "Enter area (reMin reMax imMin imMax): " и число шагов
    /// после "Enter max iterations: " и выводит renderMandelbrot(area, DEFAULT_WIDTH,
    /// DEFAULT_HEIGHT, maxIterations) построчно. Ошибка ввода — исключение
    /// std::runtime_error("input error").
    void printMandelbrot(std::istream& in, std::ostream& out) const;

    ComplexNumber first_;
    ComplexNumber second_;
};

#endif // PROGRAM_HPP
