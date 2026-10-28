#include "data_io.hpp"

// TODO: напишите решение

template <typename T>
std::vector<T> readNumbers(std::istream& in)
{
    std::vector<T> numbers;
    // TODO: напишите решение
    return numbers;
}

template <typename T>
void writeNumbers(std::ostream& out, const std::vector<T>& numbers)
{
    // TODO: напишите решение
}

// Явное создание шаблонов для int и double (определения видны только в этом файле)
template std::vector<int> readNumbers<int>(std::istream&);
template std::vector<double> readNumbers<double>(std::istream&);
template void writeNumbers<int>(std::ostream&, const std::vector<int>&);
template void writeNumbers<double>(std::ostream&, const std::vector<double>&);
