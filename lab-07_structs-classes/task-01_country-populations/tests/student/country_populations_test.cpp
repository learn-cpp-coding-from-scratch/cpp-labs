#include <sstream>

#include <gtest/gtest.h>

#include "country.hpp"
#include "country_feature.hpp"

// Ваши тесты: проверяйте функции на случаях, которые считаете важными (страна без данных за часть лет,
// пустые поля в конце строки, большие числа населения, неизвестная группа дохода),
// по образцу tests/open/*_test.cpp. Файлов может быть несколько: tests/student/<имя>_test.cpp.
// Запуск только ваших тестов: ctest --preset debug -R "\.student\."
//
// TEST(CountryStudentTest, ToStringWithoutData)
// {
//     const Country country{"Serbia", "SRB", {}};
//     EXPECT_EQ(country.toString(), "Serbia (SRB):");
// }
