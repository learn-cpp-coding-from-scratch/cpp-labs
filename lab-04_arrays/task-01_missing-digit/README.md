# Задача 1

**Дано число n. Найти наименьшую цифру, которая отсутствует в его десятичной записи.** Подумайте, над возможностью использования контейнеров `std::map`, `std::set`.

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/missing_digit.hpp` | объявления функций — не изменяйте |
| `src/missing_digit.cpp` | решение: тела функций |
| `src/missing_digit_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `src/missing_digit.cppm.example` | по желанию — решение в виде модуля C++20: переименуйте в `.cppm`, а `.hpp` и `.cpp` задачи удалите |
| `tests/open/missing_digit_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/missing_digit_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-04-task-01_missing-digit`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-04-task-01\."`, только ваши: `ctest --preset debug -R "lab-04-task-01\.student\."`.
