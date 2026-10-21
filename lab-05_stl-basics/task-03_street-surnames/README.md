# Задача 3

**Дано N пар строк из маленьких латинских букв - название улицы и фамилия человека. Нужно для каждой улицы вывести сколько различных фамилий на ней живет. Улицы выводить в лексикографическом порядке (map<string, set<string>> или vector<pair<string, string>> и std::unique)**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/street_surnames.hpp` | объявления функций — не изменяйте |
| `src/street_surnames.cpp` | решение: тела функций |
| `src/street_surnames_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/street_surnames_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/street_surnames_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-05-task-03_street-surnames`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-05-task-03\."`, только ваши: `ctest --preset debug -R "lab-05-task-03\.student\."`.
