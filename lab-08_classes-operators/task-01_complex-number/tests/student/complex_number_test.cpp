#include <gtest/gtest.h>

#include "complex_number.hpp"
#include "mandelbrot.hpp"

// Ваши тесты: проверяйте функции на случаях, которые считаете важными (z *= z и z /= z,
// деление на чисто мнимое число, z · conj(z) — действительное число, точки на границе множества
// Мандельброта), по образцу tests/open/*_test.cpp.
// Файлов может быть несколько: tests/student/<имя>_test.cpp.
// Запуск только ваших тестов: ctest --preset debug -R "\.student\."
//
// TEST(ComplexNumberStudentTest, OneDividedByI)
// {
//     const ComplexNumber result = 1.0 / ComplexNumber(0.0, 1.0);
//     EXPECT_DOUBLE_EQ(result.getRe(), 0.0);
//     EXPECT_DOUBLE_EQ(result.getIm(), -1.0);
// }
