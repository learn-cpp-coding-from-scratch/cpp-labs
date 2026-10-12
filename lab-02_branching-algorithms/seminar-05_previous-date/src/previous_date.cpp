#include <cassert>
#include <iostream>

// объявление функций; предусловие: day.month — правильная дата невисокосного года
int daysInMonth(int month);                // число дней в месяце невисокосного года
int previousDateDay(int day, int month);   // день предыдущей даты
int previousDateMonth(int day, int month); // месяц предыдущей даты

// функции тестирования
// NOLINTBEGIN(readability-magic-numbers): в проверках ожидаемые значения записываются числами
void testDaysInMonth()
{
    assert(daysInMonth(1) == 31);
    // TODO: добавьте проверки — февраль, 30-дневный месяц, декабрь
}

void testPreviousDateDay()
{
    assert(previousDateDay(5, 3) == 4);
    // TODO: добавьте проверки — первое число месяца, 1 января
}

void testPreviousDateMonth()
{
    assert(previousDateMonth(5, 3) == 3);
    // TODO: добавьте проверки — первое число месяца, 1 января
}
// NOLINTEND(readability-magic-numbers)

// точка входа
int main()
{
    // тестирование работы функций
    testDaysInMonth();
    testPreviousDateDay();
    testPreviousDateMonth();

    // TODO: ввод D и M, вывод предыдущей даты
    return 0;
}

// определение функций
constexpr int JANUARY = 1;
constexpr int DECEMBER = 12;

int daysInMonth(int month)
{
    // TODO: напишите решение
    return {};
}

int previousDateMonth(int day, int month)
{
    // TODO: напишите решение
    return {};
}

int previousDateDay(int day, int month)
{
    // TODO: напишите решение
    return {};
}
