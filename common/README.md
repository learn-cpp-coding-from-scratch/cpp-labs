# Общая библиотека cpplabs

Функции, которыми пользуются задачи всех лабораторных. Библиотека подключается ко всем программам и тестам автоматически — в `CMakeLists.txt` задачи ничего добавлять не нужно.

```
common/
├── CMakeLists.txt                 ← сборка библиотеки (не изменяйте)
├── include/cpplabs/<модуль>.hpp   ← объявления функций с комментариями
├── src/<модуль>.cpp               ← их реализация
└── tests/<модуль>_test.cpp        ← тесты библиотеки
```

| Заголовок | Функции |
|---|---|
| `cpplabs/io.hpp` | `readNumber` — вывести подсказку и прочитать целое число; `printCollection` — вывести элементы коллекции через разделитель (шаблон: подходит для `std::vector`, `std::array`, `std::set`, обычного массива) |
| `cpplabs/numbers.hpp` | `isNearlyEqual` — приближённое равенство дробных чисел (для проверок `assert` и сравнений) |

Подключение и вызов — с пространством имён `cpplabs`:

```cpp
#include <cpplabs/io.hpp>

const int count = cpplabs::readNumber("Enter n: ");
cpplabs::printCollection(numbers);         // 1, 2, 3
cpplabs::printCollection(numbers, " ");    // 1 2 3
```

Пользоваться библиотекой не обязательно: ввод и вывод можно написать и через `std::cin`, `std::cout`.

**Не изменяйте файлы библиотеки:** при получении новых лабораторных они обновляются, и ваши правки в них дадут конфликт.

## Своя библиотека: пошагово

Если одна и та же функция нужна в нескольких задачах (проверка числа на простоту, сумма цифр, переворот числа), не копируйте её из задачи в задачу — вынесите в свой модуль библиотеки. Модуль пишется **только новыми файлами в подпапках `student/`**: эти файлы ваши, обновления репозитория их не затрагивают.

На примере модуля `digits` — функции для работы с цифрами числа:

```
common/
├── include/cpplabs/student/digits.hpp   ← 1. объявления
├── src/student/digits.cpp               ← 2. реализация
└── tests/student/digits_test.cpp        ← 3. тесты
```

### 1. Заголовок — объявления

```cpp
// common/include/cpplabs/student/digits.hpp
#ifndef CPPLABS_STUDENT_DIGITS_HPP
#define CPPLABS_STUDENT_DIGITS_HPP

namespace cpplabs {

// сумма цифр неотрицательного числа: 123 → 6
int digitSum(int number);

// число, записанное теми же цифрами в обратном порядке: 123 → 321
int reverseDigits(int number);

} // namespace cpplabs

#endif // CPPLABS_STUDENT_DIGITS_HPP
```

- **Защита от повторного включения** (`#ifndef … #define … #endif`): имя `CPPLABS_STUDENT_<МОДУЛЬ>_HPP` большими буквами.
- **Пространство имён `cpplabs`**: так вызов `cpplabs::digitSum` сразу показывает, откуда функция, и её имя не столкнётся с функциями задач.
- **Только объявления** с комментарием: что функция делает, пример, ограничения на параметры. Определения обычных функций в заголовке — ошибка: заголовок подключается в несколько файлов, и функция окажется определена несколько раз (`multiple definition`). Исключения — шаблоны и константы `constexpr` (см. ниже).
- В заголовке подключайте только то, что нужно самим объявлениям (например, `<string>` для параметра `std::string`), и не пишите `using namespace std;`.

### 2. Реализация — определения

```cpp
// common/src/student/digits.cpp
#include <cpplabs/student/digits.hpp>

namespace cpplabs {

constexpr int BASE = 10;

int digitSum(int number)
{
    int sum = 0;
    for (; number > 0; number /= BASE) {
        sum += number % BASE;
    }
    return sum;
}

int reverseDigits(int number)
{
    int reversed = 0;
    for (; number > 0; number /= BASE) {
        reversed = reversed * BASE + number % BASE;
    }
    return reversed;
}

} // namespace cpplabs
```

- Первым подключается **свой заголовок**: так компилятор проверит, что заголовок самодостаточен, а объявления совпадают с определениями.
- Определения — в том же пространстве имён `cpplabs`.
- Вспомогательные функции и константы, нужные только внутри модуля (как `BASE`), в заголовок не выносите.

### 3. Тесты

```cpp
// common/tests/student/digits_test.cpp
#include <gtest/gtest.h>

#include <cpplabs/student/digits.hpp>

TEST(DigitSumTest, SeveralDigits)
{
    EXPECT_EQ(cpplabs::digitSum(123), 6);
    EXPECT_EQ(cpplabs::digitSum(0), 0);
}

TEST(ReverseDigitsTest, SeveralDigits)
{
    EXPECT_EQ(cpplabs::reverseDigits(123), 321);
    EXPECT_EQ(cpplabs::reverseDigits(120), 21);
}
```

Тесты библиотеки запускаются командой `ctest --preset debug -R "cpplabs\."` (и вместе со всеми тестами). Имена наборов тестов (`DigitSumTest`) не должны повторяться в других файлах `common/tests/`: все тесты библиотеки собираются в одну программу.

### 4. Сборка и использование в задаче

Новые файлы подхватываются при следующей сборке (**Build** / F7) — `CMakeLists.txt` менять не нужно. В задаче:

```cpp
#include <cpplabs/student/digits.hpp>

const int sum = cpplabs::digitSum(number);
```

Решение задачи по-прежнему пишется в её собственных функциях (объявленных в `include/*.hpp` задачи или в начале `src/*.cpp`): функции библиотеки вы вызываете из них, а не заменяете их.

### Шаблоны функций

Если функция должна работать с разными типами — `std::vector<int>` и `std::vector<double>`, `std::vector` и `std::array`, — напишите вместо нескольких перегрузок один шаблон. Шаблон определяется **целиком в заголовке**, файла `.cpp` для него нет: компилятор создаёт по шаблону функцию для нужного типа в месте вызова, и для этого ему нужно видеть всё тело. Образец — `printCollection` в `include/cpplabs/io.hpp`:

```cpp
// common/include/cpplabs/student/collections.hpp
#ifndef CPPLABS_STUDENT_COLLECTIONS_HPP
#define CPPLABS_STUDENT_COLLECTIONS_HPP

namespace cpplabs {

// сумма элементов коллекции; Collection — std::vector, std::array и т. п. с числами
template <typename Collection>
auto sumOf(const Collection& items)
{
    typename Collection::value_type sum{};
    for (const auto& item : items) {
        sum += item;
    }
    return sum;
}

} // namespace cpplabs

#endif // CPPLABS_STUDENT_COLLECTIONS_HPP
```

Константы, нужные и модулю, и задачам, тоже можно объявить в заголовке: `constexpr int BASE = 10;`.

### Правила

- **Только новые файлы в подпапках `student/`.** Существующие файлы `common/` не изменяйте — даже чтобы «чуть-чуть поправить» функцию: напишите свою.
- **Имена** функций не должны совпадать с функциями библиотеки и задач.
- **Ошибка в `common/` ломает сборку всех задач** всех лабораторных: после изменения модуля соберите проект и запустите его тесты.
- **Изменяя модуль позже, не ломайте задачи, которые им уже пользуются**: не меняйте смысл и параметры существующих функций — добавляйте новые. Тесты модуля помогут это заметить.
- **Сдача.** Файлы модуля добавляйте в коммит той лабораторной, в которой впервые им воспользовались (ветка `lab-NN`): преподаватель проверяет их вместе с задачей. После слияния лабораторной в `main` модуль доступен в следующих лабораторных — новую ветку `lab-NN` создавайте от обновлённой `main`.
