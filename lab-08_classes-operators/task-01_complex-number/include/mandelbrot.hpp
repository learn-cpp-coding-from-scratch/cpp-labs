#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <array>
#include <string>
#include <vector>

#include "complex_number.hpp"

/// Прямоугольник комплексной плоскости: re от reMin до reMax, im от imMin до imMax.
struct MandelbrotArea
{
    double reMin;
    double reMax;
    double imMin;
    double imMax;
};

/// Вся картинка множества при выводе в консоль 70 × 24 символа.
constexpr MandelbrotArea DEFAULT_AREA{.reMin = -2.2, .reMax = 0.8, .imMin = -1.2, .imMax = 1.2};
constexpr int DEFAULT_WIDTH = 70;
constexpr int DEFAULT_HEIGHT = 24;
constexpr int DEFAULT_MAX_ITERATIONS = 50;

/// Символы для числа шагов: от ' ' (сразу ушла в бесконечность) до '@' (точка множества).
constexpr std::array<char, 10> SHADES{' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

/// Номер шага, на котором модуль z в последовательности z₀ = 0, zₙ₊₁ = zₙ² + c
/// впервые стал больше 2, или maxIterations, если этого не произошло за maxIterations шагов:
/// escapeIterations(1, 50) == 3 (z = 0, 1, 2, 5),
/// escapeIterations(-2, 50) == 50 (z = 0, −2, 2, 2, …).
/// maxIterations ≤ 0 — исключение std::invalid_argument.
int escapeIterations(const ComplexNumber& c, int maxIterations);

/// Символ для результата escapeIterations: '@', если iterations == maxIterations,
/// иначе SHADES[iterations * (SHADES.size() - 1) / maxIterations].
char shadeFor(int iterations, int maxIterations);

/// Множество Мандельброта в прямоугольнике area: height строк по width символов.
/// Символу в столбце col и строке row соответствует c = re + im·i, где
/// re = area.reMin + (area.reMax − area.reMin) * col / width,
/// im = area.imMin + (area.imMax − area.imMin) * row / height.
/// width, height или maxIterations ≤ 0, reMin ≥ reMax или imMin ≥ imMax — исключение
/// std::invalid_argument.
std::vector<std::string> renderMandelbrot(const MandelbrotArea& area, int width, int height,
                                          int maxIterations);

#endif // MANDELBROT_HPP
