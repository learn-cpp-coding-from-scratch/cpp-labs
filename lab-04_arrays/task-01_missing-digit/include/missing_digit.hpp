#ifndef MISSING_DIGIT_HPP
#define MISSING_DIGIT_HPP

/// Наименьшая цифра, которой нет в десятичной записи числа number (отрицательного — его модуля):
/// 1234 → 0, 1023 → 4, 0 → 1. Если в записи есть все цифры от 0 до 9, возвращает -1.
int findSmallestMissingDigit(int number);

#endif // MISSING_DIGIT_HPP
