#include <exception>
#include <iostream>

#include "matrix.hpp"
#include "matrix_service.hpp"

// Демонстрация: вводит две матрицы и выводит результаты операций и функций MatrixService
int main()
{
    constexpr int RIGHT_ANGLE = 90;
    Matrix<double> first;
    Matrix<double> second;
    std::cout << "Enter matrix A (rows, columns, then elements by rows): ";
    std::cin >> first;
    std::cout << "Enter matrix B (rows, columns, then elements by rows): ";
    std::cin >> second;
    if (!std::cin) {
        std::cout << "Input error\n";
        return 1;
    }

    std::cout << "A =\n" << first << "B =\n" << second;
    std::cout << "transpose(A) =\n" << MatrixService::transpose(first);
    std::cout << "rotate(A, 90) =\n" << MatrixService::rotate(first, RIGHT_ANGLE);
    try {
        std::cout << "A * B =\n" << first * second;
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    try {
        std::cout << "det(A) = " << MatrixService::determinant(first) << '\n';
        std::cout << "inverse(A) =\n" << MatrixService::inverse(first);
        std::cout << "X from AX = B:\n" << MatrixService::solve(first, second);
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    return 0;
}
