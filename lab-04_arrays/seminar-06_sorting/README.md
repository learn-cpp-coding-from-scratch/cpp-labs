# Задача семинара 6

**Познакомиться с сортировками и реализовать: пузырьком, шейкерной, выбором.**

Визуализацию сортировок можно увидеть на ресурсах:
- Data Structure Visualizations. Сортировки https://www.cs.usfca.edu/~galles/visualization/Algorithms.html,
- https://www.youtube.com/watch?v=kPRA0W1kECg
- Танцы-сортировки: https://www.youtube.com/playlist?list=PLzZRwEvvWoO-40kTwQAvNIT0XkD_4t6_r

### Функции и тесты

| Сортировка | Функция | Набор тестов |
|---|---|---|
| пузырьком | `bubbleSort` | `BubbleSort` |
| шейкерная | `shakerSort` | `ShakerSort` |
| выбором | `selectionSort` | `SelectionSort` |

Тесты одной сортировки запускайте по имени набора: `ctest --preset debug -R BubbleSort`.

## Файлы задачи

| Файл | Что в нём |
|---|---|
| `include/sorting.hpp` | объявления функций — не изменяйте |
| `src/sorting.cpp` | решение: тела функций |
| `src/sorting_main.cpp` | программа: ввод данных, вызов функций, вывод |
| `tests/open/sorting_test.cpp` | открытые тесты — не изменяйте |
| `tests/student/sorting_test.cpp` | ваши тесты: добавляйте сюда |

Программа собирается в цель `lab-04-seminar-06_sorting`. Тесты задачи (открытые и ваши): `ctest --preset debug -R "lab-04-seminar-06\."`, только ваши: `ctest --preset debug -R "lab-04-seminar-06\.student\."`.
