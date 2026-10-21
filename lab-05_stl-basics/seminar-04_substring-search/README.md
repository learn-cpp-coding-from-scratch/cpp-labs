# Задача семинара 4

**Дан вектор пар строк. Для каждого элемента вектора вывести YES или NO если вторая строка является подстрокой первой и позицию первого вхождения (или -1, если NO).**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/substring_search.hpp` | объявления функций — не изменяйте |
| `src/substring_search.cpp` | решение: тела функций |
| `src/substring_search_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/substring_search_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/substring_search_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-05-seminar-04_substring-search`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-05-seminar-04\."`, только ваши: `ctest --preset debug -R "lab-05-seminar-04\.student\."`.
