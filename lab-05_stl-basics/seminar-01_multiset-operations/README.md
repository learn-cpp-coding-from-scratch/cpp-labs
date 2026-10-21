# Задача семинара 1

**Даны два множества A и B (std::multiset). Найти объединение (A U B), пересечение (A ∩ B), разность этих множеств (A / B, B / A).**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/multiset_operations.hpp` | объявления функций — не изменяйте |
| `src/multiset_operations.cpp` | решение: тела функций |
| `src/multiset_operations_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/multiset_operations_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/multiset_operations_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-05-seminar-01_multiset-operations`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-05-seminar-01\."`, только ваши: `ctest --preset debug -R "lab-05-seminar-01\.student\."`.
