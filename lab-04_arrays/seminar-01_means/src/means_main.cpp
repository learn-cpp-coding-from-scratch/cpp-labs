#include <iostream>
#include <vector>

#include <cpplabs/io.hpp>

#include "means.hpp"

int main()
{
    const int count = cpplabs::readNumber("Enter n: ");
    std::vector<double> numbers;
    std::cout << "Enter " << count << " numbers: ";
    for (int i = 0; i < count; ++i) {
        double number = 0.0;
        std::cin >> number;
        numbers.push_back(number);
    }

    const auto [geometricMean, arithmeticMean] = findMeans(numbers);
    if (geometricMean > 0) {
        std::cout << "Geometric mean of positive elements: " << geometricMean << '\n';
    } else {
        std::cout << "No positive elements\n";
    }
    if (arithmeticMean < 0) {
        std::cout << "Arithmetic mean of negative elements: " << arithmeticMean << '\n';
    } else {
        std::cout << "No negative elements\n";
    }
    return 0;
}
