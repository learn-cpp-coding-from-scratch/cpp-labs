#include <cassert>
#include <cmath>
#include <iostream>

// объявление функций
double calcSqrtSine(double a); // √((2a + sin|3a|) / 3,56); предусловие: 2a + sin|3a| >= 0

// функции тестирования
// NOLINTBEGIN(readability-magic-numbers): в проверках ожидаемые значения записываются числами
void testCalcSqrtSine()
{
    assert(calcSqrtSine(0.0) == 0.0);
    // TODO: добавьте проверки — a = 1, отрицательное a (модуль под синусом)
}
// NOLINTEND(readability-magic-numbers)

// точка входа
int main()
{
    // тестирование работы функций
    testCalcSqrtSine();

    // TODO: ввод a, вывод значения функции
    return 0;
}

// определение функций
double calcSqrtSine(double a)
{
    // TODO: напишите решение
    return {};
}
