#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

/// Комплексное число re_ + im_·i — только то, что нужно для сравнения на равенство.
/// Задача собирается с флагом -std=c++17: операнды == и != компилятор не переставляет.
class ComplexNumber
{
public:
    /// Число re + im·i; с одним аргументом — неявное преобразование double в ComplexNumber.
    ComplexNumber(double re = 0.0, double im = 0.0);

    [[nodiscard]] double getRe() const;
    [[nodiscard]] double getIm() const;

private:
    double re_;
    double im_;
};

/// Равенство — обычные функции (не члены класса) с одной сигнатурой для двух комплексных чисел:
/// неявное преобразование double в ComplexNumber работает для обоих операндов,
/// поэтому z == 1.0, 1.0 == z, z != 1.0 и 1.0 != z компилируются и в C++17.
/// Поля сравниваются точно, как значения double.
bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);

#endif // COMPLEX_NUMBER_HPP
