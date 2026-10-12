# Задача семинара 2

**Дан массив (vector) из n чисел. «Уплотнить» его, удалив нулевые элементы.**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/remove_zeros.hpp` | объявления функций — не изменяйте |
| `src/remove_zeros.cpp` | решение: тела функций |
| `src/remove_zeros_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/remove_zeros_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/remove_zeros_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-04-seminar-02_remove-zeros`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-04-seminar-02\."`, только ваши: `ctest --preset debug -R "lab-04-seminar-02\.student\."`.
