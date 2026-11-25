#include <exception>
#include <iostream>

#include "array.hpp"
#include "array_service.hpp"

// Демонстрация: вводит два массива и выводит результаты операций и функций ArrayService
int main()
{
    Array<int> first;
    Array<int> second;
    std::cout << "Enter array a (size, then elements): ";
    std::cin >> first;
    std::cout << "Enter array b (size, then elements): ";
    std::cin >> second;
    if (!std::cin) {
        std::cout << "Input error\n";
        return 1;
    }

    std::cout << "a = " << first << '\n';
    std::cout << "b = " << second << '\n';
    std::cout << "a * 2 = " << first * 2 << '\n';
    std::cout << "a < b: " << (first < second) << '\n';
    try {
        std::cout << "a + b = " << first + second << '\n';
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    try {
        std::cout << "sum(a) = " << ArrayService::sum(first) << '\n';
        std::cout << "average(a) = " << ArrayService::average(first) << '\n';
        std::cout << "min(a) = " << ArrayService::findMin(first) << " at index "
                  << ArrayService::findIndexMin(first) << '\n';
        std::cout << "max(a) = " << ArrayService::findMax(first) << " at index "
                  << ArrayService::findIndexMax(first) << '\n';
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    return 0;
}
