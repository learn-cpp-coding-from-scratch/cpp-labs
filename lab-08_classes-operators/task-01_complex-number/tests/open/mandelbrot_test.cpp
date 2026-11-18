#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "mandelbrot.hpp"

TEST(MandelbrotTest, PointsOfTheSet)
{
    EXPECT_EQ(escapeIterations(ComplexNumber(0.0), 50), 50);
    EXPECT_EQ(escapeIterations(ComplexNumber(-1.0), 50), 50);
    EXPECT_EQ(escapeIterations(ComplexNumber(-2.0), 50), 50); // граница: модуль остаётся равным 2
    EXPECT_EQ(escapeIterations(ComplexNumber(0.0, 1.0), 50), 50);
}

TEST(MandelbrotTest, PointsOutsideTheSet)
{
    EXPECT_EQ(escapeIterations(ComplexNumber(1.0), 50), 3); // z = 0, 1, 2, 5
    EXPECT_EQ(escapeIterations(ComplexNumber(2.0), 50), 2); // z = 0, 2, 6
    EXPECT_EQ(escapeIterations(ComplexNumber(0.5, 0.5), 50), 5);
}

TEST(MandelbrotTest, Shade)
{
    EXPECT_EQ(shadeFor(50, 50), '@');
    EXPECT_EQ(shadeFor(0, 50), ' ');
    EXPECT_EQ(shadeFor(3, 50), ' ');
    EXPECT_EQ(shadeFor(6, 50), '.');
    EXPECT_EQ(shadeFor(49, 50), '%');
}

TEST(MandelbrotTest, RenderSize)
{
    const std::vector<std::string> lines = renderMandelbrot(DEFAULT_AREA, 70, 24, 50);
    ASSERT_EQ(lines.size(), std::size_t{24});
    for (const std::string& line : lines) {
        EXPECT_EQ(line.size(), std::size_t{70});
    }
}

TEST(MandelbrotTest, RealAxisInsideTheSet)
{
    // Строка 12 — im = 0; столбцы 5…57 — re от −1.99 до 0.24, отрезок [−2; 0.25] целиком в множестве
    const std::vector<std::string> lines = renderMandelbrot(DEFAULT_AREA, 70, 24, 50);
    ASSERT_EQ(lines.size(), std::size_t{24});
    EXPECT_EQ(lines[12].substr(5, 53), std::string(53, '@'));
    EXPECT_EQ(lines[12][0], ' '); // re = −2.2 — вне множества, сразу
}

TEST(MandelbrotTest, InvalidArguments)
{
    EXPECT_THROW(escapeIterations(ComplexNumber(), 0), std::invalid_argument);
    EXPECT_THROW(renderMandelbrot(DEFAULT_AREA, 0, 24, 50), std::invalid_argument);
    EXPECT_THROW(renderMandelbrot(MandelbrotArea{1.0, -1.0, -1.0, 1.0}, 70, 24, 50), std::invalid_argument);
}
