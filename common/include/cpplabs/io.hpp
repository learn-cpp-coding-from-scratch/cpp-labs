#ifndef CPPLABS_IO_HPP
#define CPPLABS_IO_HPP

#include <iostream>
#include <string>

namespace cpplabs {

// выводит элементы коллекции через разделитель и переводит строку: {1, 2, 3} → "1, 2, 3".
// Collection — любой контейнер, который можно перебрать циклом for (const auto& item : items)
// и элементы которого выводятся оператором <<: std::vector, std::array, std::set, обычный массив.
// Шаблон функции определяется целиком в заголовке: компилятор создаёт по нему функцию
// для каждого типа коллекции в месте вызова
template <typename Collection>
void printCollection(const Collection& items, const std::string& delimiter = ", ",
                     std::ostream& out = std::cout)
{
    bool isFirst = true; // перед первым элементом разделителя нет
    for (const auto& item : items) {
        if (!isFirst) {
            out << delimiter;
        }
        out << item;
        isFirst = false;
    }
    out << '\n';
}

// выводит подсказку и читает целое число оператором >>.
// Если введено не целое число или ввод закончился, возвращает 0; после ошибки ввода поток остаётся
// в состоянии ошибки, и следующие чтения из него тоже не выполняются
int readNumber(const std::string& prompt, std::istream& in = std::cin,
               std::ostream& out = std::cout);

} // namespace cpplabs

#endif // CPPLABS_IO_HPP
