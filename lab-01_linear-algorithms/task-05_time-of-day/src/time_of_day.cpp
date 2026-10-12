#include <cassert>
#include <iostream>

// объявление функций; предусловие: secondsSinceNewYear >= 0, год невисокосный
int hoursOfDay(int secondsSinceNewYear);      // часы от начала суток, 0..23
int minutesOfHour(int secondsSinceNewYear);   // минуты от начала часа, 0..59
int secondsOfMinute(int secondsSinceNewYear); // секунды от начала минуты, 0..59

// функции тестирования: типичный случай, граница, ±1 от границы, «неудобный» случай
// NOLINTBEGIN(readability-magic-numbers): в проверках ожидаемые значения записываются числами
void testHoursOfDay()
{
    assert(hoursOfDay(3661) == 1); // 1 ч 1 мин 1 с
    // TODO: добавьте проверки — полночь, конец суток, вторые сутки, конец года
}

void testMinutesOfHour()
{
    assert(minutesOfHour(3661) == 1);
    // TODO: добавьте проверки — границы минуты и часа, вторые сутки
}

void testSecondsOfMinute()
{
    assert(secondsOfMinute(3661) == 1);
    // TODO: добавьте проверки — границы минуты, вторые сутки
}
// NOLINTEND(readability-magic-numbers)

// точка входа
int main()
{
    // тестирование работы функций
    testHoursOfDay();
    testMinutesOfHour();
    testSecondsOfMinute();

    // TODO: ввод числа секунд, вывод часов, минут и секунд
    return 0;
}

// определение функций
constexpr int SECONDS_PER_MINUTE = 60;
constexpr int MINUTES_PER_HOUR = 60;
constexpr int HOURS_PER_DAY = 24;
constexpr int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
constexpr int SECONDS_PER_DAY = SECONDS_PER_HOUR * HOURS_PER_DAY;

int hoursOfDay(int secondsSinceNewYear)
{
    // TODO: напишите решение
    return {};
}

int minutesOfHour(int secondsSinceNewYear)
{
    // TODO: напишите решение
    return {};
}

int secondsOfMinute(int secondsSinceNewYear)
{
    // TODO: напишите решение
    return {};
}
