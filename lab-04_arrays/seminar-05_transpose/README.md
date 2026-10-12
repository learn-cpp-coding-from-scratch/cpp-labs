# Задача семинара 5

**Выполните транспонирование массива размерности n x m (полученная из исходной матрицы заменой строк на столбцы).**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/transpose.hpp` | объявления функций — не изменяйте |
| `src/transpose.cpp` | решение: тела функций |
| `src/transpose_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/transpose_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/transpose_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-04-seminar-05_transpose`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-04-seminar-05\."`, только ваши: `ctest --preset debug -R "lab-04-seminar-05\.student\."`.
