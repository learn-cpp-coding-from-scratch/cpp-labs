#include <gtest/gtest.h>

#include "rational_number.hpp"

// Ваши тесты: проверяйте функции на случаях, которые считаете важными (отрицательные числитель
// и знаменатель, нулевой результат, операции дроби с самой собой: r /= r, сравнение дробей,
// для которых сравнение по полям дало бы неверный порядок), по образцу tests/open/*_test.cpp.
// Файлов может быть несколько: tests/student/<имя>_test.cpp.
// Запуск только ваших тестов: ctest --preset debug -R "\.student\."
//
// TEST(RationalNumberStudentTest, BothNegative)
// {
//     const RationalNumber number{-6, -8};
//     EXPECT_EQ(number, RationalNumber(3, 4));
// }
