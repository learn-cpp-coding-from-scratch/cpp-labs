# Задача семинара 3

**Дан текстовый файл. Построить частотный словарь слов этого текста. Знаки препинания в словах игнорировать (std::map).**

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/word_frequency.hpp` | объявления функций — не изменяйте |
| `src/word_frequency.cpp` | решение: тела функций |
| `src/word_frequency_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/word_frequency_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/word_frequency_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-05-seminar-03_word-frequency`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-05-seminar-03\."`, только ваши: `ctest --preset debug -R "lab-05-seminar-03\.student\."`.
