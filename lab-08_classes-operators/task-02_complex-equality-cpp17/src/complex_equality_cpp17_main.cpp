#include <iostream>

#include "complex_number.hpp"

int main()
{
    const ComplexNumber z{1.0, 0.0};
    std::cout << std::boolalpha;
    std::cout << "z == 1.0: " << (z == 1.0) << '\n';
    std::cout << "z != 1.0: " << (z != 1.0) << '\n';
    std::cout << "1.0 == z: " << (1.0 == z) << '\n';
    std::cout << "1.0 != z: " << (1.0 != z) << '\n';
}
